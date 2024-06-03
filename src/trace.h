#ifndef TRACE_H
# define TRACE_H

# include <stdint.h>

# undef _POSIX_C_SOURCE
# define _POSIX_C_SOURCE 199309L
# include <sys/signal.h>

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
        TC_NEXT_STEP = PTRACE_SINGLESTEP,
        TC_SYSCALL = PTRACE_SYSCALL,
    } at;
    int (*func)();
    void* param;
} trace_callback_t;

pid_t create_tracee(char* file, char* argv[], char* envp[]);
int trace_loop(pid_t tracee_pid, int* status, trace_callback_t callbacks);

struct i386_user_regs_struct {
	uint32_t ebx;
	uint32_t ecx;
	uint32_t edx;
	uint32_t esi;
	uint32_t edi;
	uint32_t ebp;
	uint32_t eax;
	uint32_t xds;
	uint32_t xes;
	uint32_t xfs;
	uint32_t xgs;
	uint32_t orig_eax;
	uint32_t eip;
	uint32_t xcs;
	uint32_t eflags;
	uint32_t esp;
	uint32_t xss;
};

typedef struct regs_s {
    union
    {
        struct user_regs_struct x86_64_r;
        struct i386_user_regs_struct i386_r;
    };
    enum {R_I386, R_86_64} class;
} regs_t;

int tracee_get_regs(pid_t tracee_pid, regs_t* regs);
int tracee_get_siginfo(pid_t tracee_pid, siginfo_t* siginfo);

#endif
