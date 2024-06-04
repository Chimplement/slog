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

int get_exit_code(int status) {
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    if (WIFSIGNALED(status))
        return (WTERMSIG(status) + 128);
    return (0);
}
