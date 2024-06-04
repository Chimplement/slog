#ifndef PROC_H
# define PROC_H

pid_t create_child(char* file, char* argv[], char* envp[]);
int get_exit_code(int status);

#endif
