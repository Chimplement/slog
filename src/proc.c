#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>

pid_t create_child(char* file, char* argv[], char* envp[]) {
    const pid_t pid = fork();
    if (pid == -1) return (-1);
    if (pid == 0) {
        execve(file, argv, envp);
        exit(1);
    }
    return (pid);
}

void exit_using_status(int status) {
    if (WIFEXITED(status))
        exit(WEXITSTATUS(status));
    if (WIFSIGNALED(status))
        exit(WTERMSIG(status) + 128);
    exit(0);
}