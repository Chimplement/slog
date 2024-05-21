#include <unistd.h>
#include <fcntl.h>

#include "file.h"

size_t open_and_read(char* file, void* buffer, size_t buffer_size) {
    int fd = open(file, O_RDONLY);
    if (fd == -1) return (-1);

    size_t bytes_read = read(fd, buffer, buffer_size);

    close(fd);
    return (bytes_read);
}