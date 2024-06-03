#ifndef SYSCALL_LOG_H
# define SYSCALL_LOG_H

# include <stdint.h>

# include <sys/types.h>

typedef struct syscall_info_s {
    const char* name;
    const char* argument_format;
    unsigned long calls;
    unsigned long errors;
    double seconds;
} syscall_info_t;

int syscall_log(pid_t tracee_pid, int* status);

int syscall_count(pid_t tracee_pid, int* status);

void syscall_log_summary();

#endif
