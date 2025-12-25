#include <stdlib.h>
#include <string.h>
#include "arbitrary_util.h"

Node *multiply(const Node *a, const Node *b) {
    if (a == NULL || b == NULL) return NULL;

    Node *total_result = NULL;
    int position = 0;

    for (const Node *b_ptr = b; b_ptr != NULL; b_ptr = b_ptr->next) {
        const int digit = b_ptr->digit;
        Node *partial = multiply_by_digit(a, digit);
        shift_list(&partial, position);
        if (total_result == NULL) {
            total_result = partial;
        } else {
            Node *new_total = add_lists(total_result, partial);
            free_list(total_result);
            free_list(partial);
            total_result = new_total;
        }
        position++;
    }

    return total_result;
}

Node *multiply_by_digit(const Node *src, const int digit) {
    if (digit == 0) return NULL;
    if (digit == 1) return copy_list(src);

    Node *result_head = NULL, *result_tail = NULL;
    const Node *ptr = src;
    int carry = 0;

    while (ptr != NULL || carry > 0) {
        int sum = carry;
        if (ptr != NULL) {
            sum += ptr->digit * digit;
            ptr = ptr->next;
        }

        append_node(&result_head, &result_tail, sum % 10);
        carry = sum / 10;
    }
    return result_head;
}

Node *add_lists(const Node *a, const Node *b) {
    Node *result_head = NULL;
    Node *result_tail = NULL;

    const Node *ptr_a = a;
    const Node *ptr_b = b;
    int carry = 0;

    while (ptr_a != NULL || ptr_b != NULL || carry > 0) {
        int sum = carry;
        if (ptr_a != NULL) {
            sum += ptr_a->digit;
            ptr_a = ptr_a->next;
        }
        if (ptr_b != NULL) {
            sum += ptr_b->digit;
            ptr_b = ptr_b->next;
        }

        append_node(&result_head, &result_tail, sum % 10);
        carry = sum / 10;
    }
    return result_head;
}

void shift_list(Node **head, const int positions) {
    if (*head == NULL) return;
    for (int i = 0; i < positions; i++) {
        push_front(head, 0);
    }
}

Node *string_to_list(const char *input) {
    Node *head = NULL;
    for (const char *ptr = input; *ptr != '\0'; ptr++) {
        push_front(&head, *ptr - '0');
    }
    return head;
}