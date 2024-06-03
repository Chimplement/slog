#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <elf.h>
#include <stdio.h>

#include <sys/types.h>

#include "options.h"
#include "env.h"
#include "path.h"
#include "proc.h"
#include "trace.h"
#include "syscall_log.h"
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
    
    pid_t tracee_pid = is_oks(create_tracee(file, argv, envp), "Failed to initialize tracee");
    int status;
    is_ok(trace_loop(
        tracee_pid,
        &status,
        (trace_callback_t) {
                TC_SYSCALL,
                options.summary ? syscall_count : syscall_log,
                NULL
        }
    ), "Unexpected error while tracing the process");
    
    int exit_code = get_exit_code(status);
    if (options.summary)
        syscall_log_summary();
    else
        fprintf(stderr, "+++ exited with %i +++\n", exit_code);
    return(exit_code);
}
