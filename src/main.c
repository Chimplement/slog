#include <stddef.h>

#include "options.h"
#include "env.h"
#include "result.h"

int main(int argc, char* argv[], char *envp[]) {
	options_t options;
	is_ok(parse_options(&options, &argc, &argv), NULL);
	char* path = env_get(envp, "PATH");
	//locate argv[0]
	//check 32-bit or 64-bit
	//start child
	//trace child
	(void) envp, (void) path;
}
