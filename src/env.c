#include <stddef.h>
#include <string.h>

#include "env.h"

char* env_find(char *envp[], char* var_name) {
	const size_t var_name_length = strlen(var_name);
	while (*envp != NULL) {
		if (!strncmp(*envp, var_name, var_name_length) && (*envp)[var_name_length] == '=') {
			return (*envp);
		}
		envp++;
	}
	return (NULL);
}

char* env_get(char *envp[], char* var_name) {
	char* var = env_find(envp, var_name);
	if (var == NULL) return (NULL);
	return (var + strlen(var_name) + 1);
}
