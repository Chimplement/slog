#include <stdio.h>
#include <stdlib.h>

#include "result.h"

static void print_error(char* error_message) {
	if (error_message == NULL) return;
	fprintf(stderr, "Error: %s\n", error_message);
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
