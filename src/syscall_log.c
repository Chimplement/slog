#include "trace.h"

#include "syscall_log.h"

int log_syscall_call(pid_t pid, void* syscall_table) {
    (void) pid;
    (void) syscall_table;
    return (TC_OK);
}

int log_syscall_return(pid_t pid, void* syscall_table) {
    (void) pid;
    (void) syscall_table;
    return (TC_OK);
}
