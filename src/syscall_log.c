#include "trace.h"

#include "syscall_log.h"

int syscall_log_call(pid_t pid, syscall_table_t* syscall_table) {
    (void) pid;
    (void) syscall_table;
    return (TC_OK);
}

int syscall_log_return(pid_t pid, syscall_table_t* syscall_table) {
    (void) pid;
    (void) syscall_table;
    return (TC_OK);
}

int syscall_count_call(pid_t pid, syscall_table_t* syscall_table) {
    (void) pid;
    (void) syscall_table;
    return (TC_OK);
}

int syscall_count_return(pid_t pid, syscall_table_t* syscall_table) {
    (void) pid;
    (void) syscall_table;
    return (TC_OK);
}