#ifndef ARBITRARY_MULTIPLICATION_ARBITRARY_UTIL_H
#define ARBITRARY_MULTIPLICATION_ARBITRARY_UTIL_H

#include "linked_list.h"

Node *multiply(const Node *a, const Node *b);
Node *multiply_by_digit(const Node *src, int digit);
Node *add_lists(const Node *a, const Node *b);
void shift_list(Node **head, int positions);
Node *string_to_list(const char *input);

#endif //ARBITRARY_MULTIPLICATION_ARBITRARY_UTIL_H