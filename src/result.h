#ifndef RESULT_H
# define RESULT_H

void print_error(char* error_message);

void exit_error_message(char* error_message);

int is_ok(int status, char* error_message);
int is_oks(int status, char* error_message);
void* is_okp(void* pointer, char* error_message);

#endif
