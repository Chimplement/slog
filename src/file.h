#ifndef FILE_H
# define FILE_H

# include <stddef.h>

size_t open_and_read(char* file, void* buffer, size_t buffer_size);

#endif
