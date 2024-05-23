#include <stddef.h>
#define _POSIX_C_SOURCE 1
#include <signal.h>

#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/wait.h>

#include "proc.h"
#include "sig.h"

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

int trace_loop(pid_t tracee_pid) {
    (void) tracee_pid;
    return (0);
}
