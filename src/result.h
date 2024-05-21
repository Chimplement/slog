#ifndef RESULT_H
# define RESULT_H

int is_ok(int status, char* error_message);
void* is_okp(void* pointer, char* error_message);

#endif
