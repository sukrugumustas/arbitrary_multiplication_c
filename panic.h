#ifndef ARBITRARY_MULTIPLICATION_PANIC_H
#define ARBITRARY_MULTIPLICATION_PANIC_H

#define ERR_NO_INPUT (-1)
#define ERR_INVALID_INPUT (-2)
#define ERR_MEMORY_LEAK (-9)

const char* err_msg(int code);
void terminate(void *ptr_to_free, int code);

#endif //ARBITRARY_MULTIPLICATION_PANIC_H