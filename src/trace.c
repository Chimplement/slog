#include <stddef.h>
#define _POSIX_C_SOURCE 1
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
    
    return (pid);
}

int trace_loop(pid_t tracee_pid, int* status, trace_callback_t callbacks[], size_t callback_count) {
    size_t i = 0;

    do {
        if (ptrace((enum __ptrace_request)callbacks[i].at, tracee_pid, 0, 0) == -1)
            return (-1);
        if (wait_and_block(tracee_pid, status) == -1)
            return (-1);
        switch (callbacks[i].func(tracee_pid, callbacks[i].param))
        {
            case TC_OK:
                break;
            case TC_EXIT:
                return (0);
            case TC_ERROR:
                return (-1);
        }
        i++;
        if (i >= callback_count) i = 0;
    } while (!WIFEXITED(*status));
    return (0);
}

int get_regs(pid_t tracee_pid, struct user_regs_struct* regs) {
    struct iovec regs_iov = {.iov_base = regs, .iov_len = sizeof(*regs)};

    return (ptrace(PTRACE_GETREGSET, tracee_pid, 1, &regs_iov));

}
