#ifndef ARBITRARY_MULTIPLICATION_TEXT_UTIL_H
#define ARBITRARY_MULTIPLICATION_TEXT_UTIL_H

#include <stdbool.h>

char *take_input(int number_index);
bool is_zero(const char *input);
bool check_and_strip_sign(const char **input);

#endif //ARBITRARY_MULTIPLICATION_TEXT_UTIL_H