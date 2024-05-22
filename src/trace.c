#define _POSIX_C_SOURCE 1
#include <signal.h>

#include <sys/types.h>
#include <sys/ptrace.h>

#include "proc.h"

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
    return (pid);
}
