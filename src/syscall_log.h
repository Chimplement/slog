#ifndef SYSCALL_LOG_H
# define SYSCALL_LOG_H

# include <stdint.h>

# include <sys/types.h>

typedef struct syscall_info_s {
    const char* name;
    const char* argument_format;
} syscall_info_t;

typedef struct syscall_table_s {
    uint8_t elf_class;
    size_t size;
    syscall_info_t* content;
} syscall_table_t;

int syscall_log_call(pid_t pid, int* status, syscall_table_t* syscall_table);
int syscall_log_return(pid_t pid, int* status, syscall_table_t* syscall_table);

int syscall_count_call(pid_t pid, int* status, syscall_table_t* syscall_table);
int syscall_count_return(pid_t pid, int* status, syscall_table_t* syscall_table);

void syscall_log_summary(syscall_table_t syscall_table);

#endif
