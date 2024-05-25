#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <elf.h>

#include <sys/types.h>

#include "options.h"
#include "env.h"
#include "path.h"
#include "elf_info.h"
#include "proc.h"
#include "trace.h"
#include "syscall_log.h"
#include "result.h"

static syscall_info_t syscall_table_content_x86_32[] = {
#include <syscall_tables/x86_32.h>
};

static syscall_info_t syscall_table_content_x86_64[] = {
#include <syscall_tables/x86_64.h>
};

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

    syscall_table_t syscall_table;
    switch (elf_class)
    {
        case ELFCLASS32:
            syscall_table.content = syscall_table_content_x86_32;
            syscall_table.size = sizeof(syscall_table_content_x86_32) /\
                                sizeof(*syscall_table_content_x86_32);
            break;
        case ELFCLASS64:
            syscall_table.content = syscall_table_content_x86_64;
            syscall_table.size = sizeof(syscall_table_content_x86_64) /\
                                sizeof(*syscall_table_content_x86_64);
            break;
        default:
            is_ok(-1, "Invalid  ELF class");
    }
    
    pid_t tracee_pid = is_oks(create_tracee(file, argv, envp), "Failed to initialize tracee");
    int status;
    is_ok(trace_loop(
        tracee_pid,
        &status,
        (trace_callback_t[]) {
            {
                TC_SYSCALL,
                options.summary ? syscall_count_call : syscall_log_call,
                &syscall_table
            },
            {
                TC_SYSCALL,
                options.summary ? syscall_count_return : syscall_log_return,
                &syscall_table
            },
        },
        2
    ), "Unexpected error while tracing the process");
    if (options.summary) {} //display summary
    exit_using_status(status);
}
