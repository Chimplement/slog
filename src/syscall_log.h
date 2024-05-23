#ifndef SYSCALL_LOG_H
# define SYSCALL_LOG_H

# include <sys/types.h>

int log_syscall_call(pid_t pid, void* syscall_table);
int log_syscall_return(pid_t pid, void* syscall_table);

#endif
