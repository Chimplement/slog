#ifndef SYSCALL_LOG_H
# define SYSCALL_LOG_H

# include <sys/types.h>

int syscall_log_call(pid_t pid, void* syscall_table);
int syscall_log_return(pid_t pid, void* syscall_table);

int syscall_count_call(pid_t pid, void* syscall_table);
int syscall_count_return(pid_t pid, void* syscall_table);

#endif
