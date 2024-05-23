#ifndef PROC_H
# define PROC_H

pid_t create_child(char* file, char* argv[], char* envp[]);
void exit_using_status(int status);

#endif