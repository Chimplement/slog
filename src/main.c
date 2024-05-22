#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <elf.h>

#include <sys/types.h>

#include "options.h"
#include "env.h"
#include "path.h"
#include "elf_info.h"
#include "trace.h"
#include "result.h"

int main(int argc, char* argv[], char *envp[]) {
	options_t options;
	is_ok(parse_options(&options, &argc, &argv), NULL);
	is_ok(argc == 0, "Missing arguments");

	char* file;
	if (strchr(argv[0], '/') == NULL) {
		char* path = env_get(envp, "PATH");
		file = is_okp(path_locate(path, argv[0], X_OK | R_OK), "Cannot find the executable");
	} else {
		file = argv[0];
		is_ok(access(argv[0], X_OK | R_OK), "Cannot find the executable");
	}

	uint8_t* elf_ident = is_okp(elf_read_ident(file), "Invalid ELF identifier");
	uint8_t elf_class = elf_ident[EI_CLASS];
	
	pid_t tracee_pid = is_oks(create_tracee(file, argv, envp), "Failed to initialize tracee");
	//trace child
	(void) elf_class;
}
