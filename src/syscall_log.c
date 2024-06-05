#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#include <sys/syscall.h>
#include <sys/wait.h>

#include "trace.h"

#include "syscall_log.h"

static syscall_info_t syscall_table_i386[] = {
#include <syscall_tables/i386.h>
};

static syscall_info_t syscall_table_x86_64[] = {
#include <syscall_tables/x86_64.h>
};

void check_class_switch(pid_t tracee_pid, regs_t regs) {
    static int old_class = R_86_64;

    if ((int)regs.class != old_class) {
        old_class = regs.class;
        fprintf(stderr, "[ Process PID=%i runs in %s mode. ]\n",
            tracee_pid, regs.class == R_86_64 ? "64 bit" : "32 bit"
        );
    }
}

int syscall_log_call(regs_t regs, unsigned long syscall_num) {
    syscall_info_t syscall_info = regs.class == R_86_64 ? syscall_table_x86_64[syscall_num] : syscall_table_i386[syscall_num];
    fprintf(stderr, "%s(", syscall_info.name);
    
    if (regs.class == R_86_64) {
        fprintf(stderr, syscall_info.argument_format,
            regs.x86_64_r.rdi, regs.x86_64_r.rsi, regs.x86_64_r.rdx,
            regs.x86_64_r.rcx, regs.x86_64_r.r8, regs.x86_64_r.r9
        );
        if (syscall_num == SYS_exit || syscall_num == SYS_exit_group) {
            fprintf(stderr, ") = ?\n");
            return (TC_EXIT);
        }
    } else {
        fprintf(stderr, syscall_info.argument_format,
            regs.i386_r.ebx, regs.i386_r.ecx, regs.i386_r.edx,
            regs.i386_r.esi, regs.i386_r.edi, regs.i386_r.ebp
        );
        if (syscall_num == 1 || syscall_num == 252) {
            fprintf(stderr, ") = ?\n");
            return (TC_EXIT);
        }
    }
    return (TC_OK);
}

int syscall_log_return(pid_t tracee_pid, regs_t regs, int* status) {
    if (WSTOPSIG(*status) != (SIGTRAP | 0x80)) {
        siginfo_t siginfo;
        if (tracee_get_siginfo(tracee_pid, &siginfo) == -1)
            return (TC_ERROR);

        fprintf(stderr, "--- Signal: %s {si_signo=%i, si_code=%i, si_pid=%i} ---\n", strsignal(siginfo.si_signo), siginfo.si_signo, siginfo.si_code, siginfo.si_pid);
    } else {
        if (regs.class == R_86_64)
            fprintf(stderr, ") = %lli\n", regs.x86_64_r.rax);
        else
            fprintf(stderr, ") = %i\n", (int)regs.i386_r.eax);
    }
    check_class_switch(tracee_pid, regs);
    return (TC_OK);
}

int syscall_log(pid_t tracee_pid, int* status) {
    regs_t regs;
    if (tracee_get_regs(tracee_pid, &regs) == -1) {
        return (TC_ERROR);
    }

    unsigned long syscall_num = regs.class == R_86_64 ? regs.x86_64_r.orig_rax : regs.i386_r.orig_eax;
    bool is_call = regs.class == R_86_64 ?
        (long) regs.x86_64_r.rax == -ENOSYS :
        (int) regs.i386_r.eax == -ENOSYS;

    if (regs.class == R_86_64 ?
        (syscall_num >= sizeof(syscall_table_x86_64)/sizeof(*syscall_table_x86_64)) :
        (syscall_num >= sizeof(syscall_table_i386)/sizeof(*syscall_table_i386))
    )
        return (TC_ERROR);

    if (is_call)
        return(syscall_log_call(regs, syscall_num));
    else
        return(syscall_log_return(tracee_pid, regs, status));
}

int syscall_count_call(syscall_info_t* syscall_info, regs_t regs, unsigned long syscall_num) {
    if (regs.class == R_86_64) {
        if (syscall_num == SYS_exit || syscall_num == SYS_exit_group)
            return (TC_OK);
    } else {
        if (syscall_num == 1 || syscall_num == 252)
            return (TC_OK);
    }
    
    syscall_info->calls += 1;
    return (TC_OK);
}

int syscall_count_return(syscall_info_t* syscall_info, regs_t regs, int* status) {
    if (WSTOPSIG(*status) != (SIGTRAP | 0x80)) {
        return (TC_OK);
    }

    if (regs.class == R_86_64) {
        if ((long)regs.x86_64_r.rax < 0)
            syscall_info->errors += 1;
    } else {
        if ((int)regs.i386_r.eax < 0)
            syscall_info->errors += 1;
    }
    return (TC_OK);
}

int syscall_count(pid_t tracee_pid, int* status) {
    static double start_time = 0;

    regs_t regs;
    if (tracee_get_regs(tracee_pid, &regs) == -1) {
        return (TC_ERROR);
    }
    check_class_switch(tracee_pid, regs);

    unsigned long syscall_num = regs.class == R_86_64 ? regs.x86_64_r.orig_rax : regs.i386_r.orig_eax;
    bool is_call = regs.class == R_86_64 ?
        (long) regs.x86_64_r.rax == -ENOSYS :
        (int) regs.i386_r.eax == -ENOSYS;

    if (regs.class == R_86_64 ?
        (syscall_num >= sizeof(syscall_table_x86_64)/sizeof(*syscall_table_x86_64)) :
        (syscall_num >= sizeof(syscall_table_i386)/sizeof(*syscall_table_i386))
    )
        return (TC_ERROR);

    syscall_info_t* syscall_info = regs.class == R_86_64 ? &syscall_table_x86_64[syscall_num] : &syscall_table_i386[syscall_num];

    if (is_call) {
        start_time = clock();
        return(syscall_count_call(syscall_info, regs, syscall_num));
    } else {
        syscall_info->seconds += (double)(clock() - start_time) / CLOCKS_PER_SEC;
        return(syscall_count_return(syscall_info, regs, status));
    }
}

void syscall_log_summary_64() {
    unsigned long total_calls = 0;
    unsigned long total_errors = 0;
    double total_seconds = 0.0;
    for (size_t i = 0; i < sizeof(syscall_table_x86_64)/sizeof(*syscall_table_x86_64); i++) {
        syscall_info_t syscall_info = syscall_table_x86_64[i];
        total_calls += syscall_info.calls;
        total_errors += syscall_info.errors;
        total_seconds += syscall_info.seconds;
    }

    fprintf(stderr, "%% time     seconds  usecs/call     calls    errors syscall\n");
    fprintf(stderr, "------ ----------- ----------- --------- --------- ----------------\n");
    for (size_t i = 0; i < sizeof(syscall_table_x86_64)/sizeof(*syscall_table_x86_64); i++) {
        syscall_info_t syscall_info = syscall_table_x86_64[i];
        if (syscall_info.calls == 0)
            continue;
        fprintf(stderr, "%6.2f %11.6f %11lu %9lu %9lu %-16s\n",
            (syscall_info.seconds / total_seconds) * 100,
            syscall_info.seconds,
            (long unsigned) (syscall_info.seconds * 1000000 / syscall_info.calls),
            syscall_info.calls,
            syscall_info.errors,
            syscall_info.name
        );
    }
    fprintf(stderr, "------ ----------- ----------- --------- --------- ----------------\n");
    fprintf(stderr, "100.00 %11.6f %11lu %9lu %9lu total\n",
        total_seconds,
        (long unsigned) (total_seconds * 1000000 / total_calls),
        total_calls,
        total_errors
    );
}

void syscall_log_summary_32() {
    unsigned long total_calls = 0;
    unsigned long total_errors = 0;
    double total_seconds = 0.0;
    for (size_t i = 0; i < sizeof(syscall_table_i386)/sizeof(*syscall_table_i386); i++) {
        syscall_info_t syscall_info = syscall_table_i386[i];
        total_calls += syscall_info.calls;
        total_errors += syscall_info.errors;
        total_seconds += syscall_info.seconds;
    }

    if (total_calls == 0)
        return ;

    fprintf(stderr, "System call usage summary for 32 bit mode:\n");
    fprintf(stderr, "%% time     seconds  usecs/call     calls    errors syscall\n");
    fprintf(stderr, "------ ----------- ----------- --------- --------- ----------------\n");
    for (size_t i = 0; i < sizeof(syscall_table_i386)/sizeof(*syscall_table_i386); i++) {
        syscall_info_t syscall_info = syscall_table_i386[i];
        if (syscall_info.calls == 0)
            continue;
        fprintf(stderr, "%6.2f %11.6f %11lu %9lu %9lu %-16s\n",
            (syscall_info.seconds / total_seconds) * 100,
            syscall_info.seconds,
            (long unsigned) (syscall_info.seconds * 1000000 / syscall_info.calls),
            syscall_info.calls,
            syscall_info.errors,
            syscall_info.name
        );
    }
    fprintf(stderr, "------ ----------- ----------- --------- --------- ----------------\n");
    fprintf(stderr, "100.00 %11.6f %11lu %9lu %9lu total\n",
        total_seconds,
        (long unsigned) (total_seconds * 1000000 / total_calls),
        total_calls,
        total_errors
    );
}

void syscall_log_summary() {
    syscall_log_summary_64();
    syscall_log_summary_32();
}
