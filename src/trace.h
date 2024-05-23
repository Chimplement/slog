#ifndef TRACE_H
# define TRACE_H

pid_t create_tracee(char* file, char* argv[], char* envp[]);
int trace_loop(pid_t tracee_pid);

#endif