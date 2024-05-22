#include <getopt.h>

#include "options.h"

int parse_options(options_t* options, int* argc, char** argv[]) {
    *options = (options_t){
        .summary = false,
    };

    int opt;
    while ((opt = getopt(*argc, *argv, "c")) != -1) {
        switch (opt)
        {
            case 'c':
                options->summary = true;
                break;
            default:
                return (-1);
        }
    }
    *argv += optind;
    *argc -= optind;
    return (0);
}
