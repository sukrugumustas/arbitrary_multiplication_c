#include <stdio.h>
#include <stdlib.h>
#include "panic.h"

const char* err_msg(const int code) {
    switch (code) {
        case ERR_NO_INPUT: return "No input is given!";
        case ERR_INVALID_INPUT: return "Given input is not a valid number!";
        case ERR_MEMORY_LEAK: return "Memory allocation failed!";
        default: return "Unknown error!";
    }
}

void terminate(void *ptr_to_free, const int code) {
    if (ptr_to_free != NULL) {
        free(ptr_to_free);
    }
    fprintf(stderr, "[Exit %d] %s\n", code, err_msg(code));
    exit(code);
}
