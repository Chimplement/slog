#include <stddef.h>
#include <string.h>
#include <unistd.h>

#include <linux/limits.h>

#include "path.h"

char* path_locate(char* path, char* file_name, int mode) {
    static char path_buffer[PATH_MAX];
    const size_t file_name_length = strlen(file_name);

    while (path != NULL && *path != '\0') {
        const size_t dir_length = strcspn(path, ":");
        if (dir_length + file_name_length + 2 > PATH_MAX)
            continue;
        
        strncpy(path_buffer, path, dir_length);
        strcpy(path_buffer + dir_length, "/");
        strcpy(path_buffer + dir_length + 1, file_name);
        if (access(path_buffer, mode) == 0)
            return (path_buffer);

        if (path[dir_length] == '\0') break;
        path += dir_length + 1;
    }

    if (access(file_name, mode) == 0) 
        return (file_name);
    return (NULL);
}
