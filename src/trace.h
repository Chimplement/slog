#ifndef TRACE_H
# define TRACE_H

# include <sys/types.h>
# include <sys/user.h>
# include <sys/ptrace.h>

enum {
    TC_OK = 0,
    TC_EXIT = 1,
    TC_ERROR = -1,
};

typedef struct trace_callback_s {
    enum {
        TC_NEXT_STEP = PTRACE_SYSCALL,
        TC_SYSCALL = PTRACE_SINGLESTEP,
    } at;
    int (*func)();
    void* param;
} trace_callback_t;

pid_t create_tracee(char* file, char* argv[], char* envp[]);
int trace_loop(pid_t tracee_pid, int* status, trace_callback_t callbacks[], size_t callback_count);

int get_regs(pid_t tracee_pid, struct user_regs_struct* regs);

#endif
