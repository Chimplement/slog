#ifndef OPTIONS_H
# define OPTIONS_H

# include <stdbool.h>

typedef struct options_s {
    bool summary;
} options_t;

int parse_options(options_t* options, int* argc, char*** argv);

#endif
