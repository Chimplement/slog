#include <stdio.h>
#include <stdlib.h>

#include "result.h"

#define ERROR_ANSI "\x1b[1;31m"
#define RESET_ANSI "\x1b[0m"

static void print_error(char* error_message) {
	if (error_message == NULL) return;
	fprintf(stderr, ERROR_ANSI"Error:"RESET_ANSI" %s\n", error_message);
}

int is_ok(int status, char* error_message) {
	if (status == 0) return (status);
	print_error(error_message);
	exit(1);
}

void* is_okp(void* pointer, char* error_message) {
	if (pointer != NULL) return (pointer);
	print_error(error_message);
	exit(1);
}
