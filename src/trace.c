#include <stddef.h>
#define _POSIX_C_SOURCE 199309L
#include <signal.h>

#include <sys/uio.h>
#include <sys/wait.h>

#include "proc.h"
#include "sig.h"

#include "trace.h"

static int wait_and_block(pid_t pid, int* status) {
    sig_unblock_interrupts();
    if (waitpid(pid, status, 0) == -1)
        return (-1);
    sig_block_interrupts();
    return (0);
}

pid_t create_tracee(char* file, char* argv[], char* envp[]) {
    const pid_t pid = create_child(file, argv, envp);
    if (pid == -1) return (-1);

    if (ptrace(PTRACE_SEIZE, pid, 0, 0) == -1) {
        kill(pid, SIGKILL);
        return (-1);
    }
    if (ptrace(PTRACE_INTERRUPT, pid, 0, 0) == -1) {
        kill(pid, SIGKILL);
        return (-1);
    }

    if (wait_and_block(pid, NULL) == -1) {
        kill(pid, SIGKILL);
        return (-1);
    }
    if (ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_EXITKILL) == -1) {
        kill(pid, SIGKILL);
        return (-1);
    }
    if (ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_TRACESYSGOOD) == -1) {
        return (-1);
    }
    
    return (pid);
}

int trace_loop(pid_t tracee_pid, int* status, trace_callback_t callback) {
    do {
        if (ptrace((enum __ptrace_request)callback.at, tracee_pid, 0, 0) == -1)
            return (-1);
        if (wait_and_block(tracee_pid, status) == -1)
            return (-1);
        if (WIFSTOPPED(*status)) {
            switch (callback.func(tracee_pid, status, callback.param))
            {
                case TC_OK:
                    break;
                case TC_EXIT:
                    break;
                case TC_ERROR:
                    return (-1);
            }
        }
    } while (!WIFEXITED(*status));
    while (!WIFEXITED(*status)) {
        if (wait_and_block(tracee_pid, status) == -1)
            return (-1);
    }
    return (0);
}

int tracee_get_regs(pid_t tracee_pid, regs_t* regs) {
    struct iovec regs_iov = {.iov_base = &regs->x86_64_r, .iov_len = sizeof(struct user_regs_struct)};

    if (ptrace(PTRACE_GETREGSET, tracee_pid, 1, &regs_iov) == -1) {
        return (-1);
    }

    if (regs_iov.iov_len == sizeof(struct i386_user_regs_struct)) {
        regs->class = R_I386;
    } else {
        regs->class = R_86_64;
    }

    return (0);
}

int tracee_get_siginfo(pid_t tracee_pid, siginfo_t* siginfo) {
    return (ptrace(PTRACE_GETSIGINFO, tracee_pid, 0, siginfo));
}
