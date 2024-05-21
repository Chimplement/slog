#include <stddef.h>
#include <string.h>
#include <unistd.h>

#include "options.h"
#include "env.h"
#include "path.h"
#include "result.h"

int main(int argc, char* argv[], char *envp[]) {
	options_t options;
	is_ok(parse_options(&options, &argc, &argv), NULL);
	char* file;
	if (strchr(argv[0], '/') == NULL) {
		char* path = env_get(envp, "PATH");
		file = is_okp(path_locate(path, argv[0], X_OK | R_OK), "Cannot find the executable");
	} else {
		file = argv[0];
		is_ok(access(argv[0], X_OK | R_OK), "Cannot find the executable");
	}
	//check 32-bit or 64-bit
	//start child
	//trace child
	(void) file;
}
