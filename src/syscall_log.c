#include <stdio.h>
#include <string.h>
#include <elf.h>
#include <errno.h>

#include <sys/syscall.h>
#include <sys/wait.h>

#include "trace.h"

#include "syscall_log.h"

int syscall_log_call(pid_t tracee_pid, int* status, syscall_table_t* syscall_table) {
    struct user_regs_struct regs;
    if (tracee_get_regs(tracee_pid, &regs) == -1) {
        return (TC_ERROR);
    }

    unsigned long long syscall_num = regs.orig_rax;
    if (syscall_num >= syscall_table->size)
        return (TC_ERROR);

    syscall_info_t syscall_info = syscall_table->content[syscall_num];
    fprintf(stderr, "%s(", syscall_info.name);
    
    if (syscall_table->elf_class == ELFCLASS32)
        fprintf(stderr, syscall_info.argument_format, regs.rbx, regs.rcx, regs.rdx, regs.rsi, regs.rdi, regs.rbp);
    else if (syscall_table->elf_class == ELFCLASS64)
        fprintf(stderr, syscall_info.argument_format, regs.rdi, regs.rsi, regs.rdx, regs.rcx, regs.r8, regs.r9);
    
    if (syscall_num == SYS_exit || syscall_num == SYS_exit_group) {
        fprintf(stderr, ") = ?\n");
        return (TC_EXIT);
    }

    (void) status;
    return (TC_OK);
}

int syscall_log_return(pid_t tracee_pid, int* status, syscall_table_t* syscall_table) {
    struct user_regs_struct regs;
    if (tracee_get_regs(tracee_pid, &regs) == -1)
        return (TC_ERROR);

    if (WSTOPSIG(*status) != (SIGTRAP | 0x80)) {
        siginfo_t siginfo;
        if (tracee_get_siginfo(tracee_pid, &siginfo) == -1)
            return (TC_ERROR);

        fprintf(stderr, "<unfinished ...>\n");
        fprintf(stderr, "--- Signal: %s {si_signo=%i, si_code=%i, si_pid=%i} ---\n", strsignal(siginfo.si_signo), siginfo.si_signo, siginfo.si_code, siginfo.si_pid);
    } else {
        fprintf(stderr, ") = %lli\n", regs.rax);
    }

    (void) syscall_table;
    return (TC_OK);
}

int syscall_log(pid_t tracee_pid, int* status, syscall_table_t* syscall_table) {
    struct user_regs_struct regs;
    if (tracee_get_regs(tracee_pid, &regs) == -1) {
        return (TC_ERROR);
    }

    if (regs.rax == (unsigned long)-ENOSYS)
        return(syscall_log_call(tracee_pid, status, syscall_table));
    else
        return(syscall_log_return(tracee_pid, status, syscall_table));
}

int syscall_count_call(pid_t tracee_pid, int* status, syscall_table_t* syscall_table) {
    struct user_regs_struct regs;
    if (tracee_get_regs(tracee_pid, &regs) == -1) {
        return (TC_ERROR);
    }

    unsigned long long syscall_num = regs.orig_rax;
    if (syscall_num >= syscall_table->size)
        return (TC_ERROR);

    if (syscall_num == SYS_exit || syscall_num == SYS_exit_group) {
        return (TC_EXIT);
    }

    syscall_info_t* syscall_info = &syscall_table->content[syscall_num];
    syscall_info->calls += 1;

    (void) status;
    return (TC_OK);
}

int syscall_count_return(pid_t tracee_pid, int* status, syscall_table_t* syscall_table) {
    struct user_regs_struct regs;
    if (tracee_get_regs(tracee_pid, &regs) == -1) {
        return (TC_ERROR);
    }

    if (WSTOPSIG(*status) != (SIGTRAP | 0x80)) {
        return (TC_OK);
    }

    unsigned long long syscall_num = regs.orig_rax;
    if (syscall_num >= syscall_table->size)
        return (TC_ERROR);

    syscall_info_t* syscall_info = &syscall_table->content[syscall_num];
    if ((long) regs.rax < 0)
        syscall_info->errors += 1;

    (void) status;
    return (TC_OK);
}

int syscall_count(pid_t tracee_pid, int* status, syscall_table_t* syscall_table) {
    struct user_regs_struct regs;
    if (tracee_get_regs(tracee_pid, &regs) == -1) {
        return (TC_ERROR);
    }

    if (regs.rax == (unsigned long)-ENOSYS)
        return(syscall_count_call(tracee_pid, status, syscall_table));
    else
        return(syscall_count_return(tracee_pid, status, syscall_table));
}

void syscall_log_summary(syscall_table_t syscall_table) {
    unsigned long total_calls = 0;
    unsigned long total_errors = 0;
    double total_seconds = 0.0;

    fprintf(stderr, "%% time     seconds  usecs/call     calls    errors syscall\n");
    fprintf(stderr, "------ ----------- ----------- --------- --------- ----------------\n");
    for (size_t i = 0; i < syscall_table.size; i++) {
        syscall_info_t syscall_info = syscall_table.content[i];
        if (syscall_info.calls == 0)
            continue;
        fprintf(stderr, "%6.2f %11.6f %11lu %9lu %9lu %-16s\n",
            0.0,
            syscall_info.seconds,
            (long unsigned) (syscall_info.seconds * 1000000),
            syscall_info.calls,
            syscall_info.errors,
            syscall_info.name
        );

        total_calls += syscall_info.calls;
        total_errors += syscall_info.errors;
        total_seconds += syscall_info.seconds;
    }
    fprintf(stderr, "------ ----------- ----------- --------- --------- ----------------\n");
    fprintf(stderr, "100.00 %11.6f %11lu %9lu %9lu total\n",
        total_seconds,
        (long unsigned) (total_seconds * 1000000),
        total_calls,
        total_errors
    );
}