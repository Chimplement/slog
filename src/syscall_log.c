#include <stdio.h>

#include <sys/syscall.h>

#include "trace.h"

#include "syscall_log.h"

int syscall_log_call(pid_t tracee_pid, syscall_table_t* syscall_table) {
    struct user_regs_struct regs;
    if (get_regs(tracee_pid, &regs) == -1)
        return (TC_ERROR);

    unsigned long long syscall_num = regs.orig_rax;
    if (syscall_num >= syscall_table->size)
        return (TC_ERROR);

    syscall_info_t syscall_info = syscall_table->content[syscall_num];
    fprintf(stderr, "%s(", syscall_info.name);
    // choose different registers if executable is 32-bit
    fprintf(stderr, syscall_info.argument_format, regs.rdi, regs.rsi, regs.rdx, regs.rcx, regs.r8, regs.r9);
    
    if (syscall_num == SYS_exit || syscall_num == SYS_exit_group) {
        fprintf(stderr, ") = ?\n");
        return (TC_EXIT);
    }

    return (TC_OK);
}

int syscall_log_return(pid_t tracee_pid, syscall_table_t* syscall_table) {
    struct user_regs_struct regs;
    if (get_regs(tracee_pid, &regs) == -1)
        return (TC_ERROR);
    
    fprintf(stderr, ") = %lli\n", regs.rax);
    (void) syscall_table;
    return (TC_OK);
}

int syscall_count_call(pid_t tracee_pid, syscall_table_t* syscall_table) {
    (void) tracee_pid;
    (void) syscall_table;
    return (TC_OK);
}

int syscall_count_return(pid_t tracee_pid, syscall_table_t* syscall_table) {
    (void) tracee_pid;
    (void) syscall_table;
    return (TC_OK);
}

void syscall_log_summary(syscall_table_t syscall_table) {
    (void) syscall_table;
}