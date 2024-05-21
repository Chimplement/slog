#ifndef ENV_H
# define ENV_H

char* env_find(char *envp[], char* var_name);
char* env_get(char *envp[], char* var_name);

#endif
