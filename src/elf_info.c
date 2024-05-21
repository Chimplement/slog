#include <string.h>
#include <strings.h>
#include <elf.h>

#include "file.h"

#include "elf_info.h"

uint8_t* elf_read_ident(char* file) {
    static uint8_t ident[EI_NIDENT];

    if (open_and_read(file, ident, EI_NIDENT) != EI_NIDENT)
        return (NULL);
    if (strncmp((char*)ident, ELFMAG, 4) != 0)
        return (NULL);

    return (ident);
}