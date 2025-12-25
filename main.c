#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "text_util.h"
#include "arbitrary_util.h"

int main(void) {
    char *number_one_str = take_input(1);
    char *number_two_str = take_input(2);

    const char *ptr_one = number_one_str;
    const char *ptr_two = number_two_str;

    const bool is_neg_one = check_and_strip_sign(&ptr_one);
    const bool is_neg_two = check_and_strip_sign(&ptr_two);
    const bool result_is_neg = is_neg_one ^ is_neg_two;

    if (is_zero(ptr_one) || is_zero(ptr_two)) {
        fprintf(stdout, "Result: 0\n");
        free(number_one_str);
        free(number_two_str);
        return 0;
    }

    Node *num_one = string_to_list(ptr_one);
    Node *num_two = string_to_list(ptr_two);

    Node *result = multiply(num_one, num_two);

    fprintf(stdout, "Result: %s", result_is_neg ? "-" : "");
    print_list(result);
    fprintf(stdout, "\n");

    free_list(num_one);
    free_list(num_two);
    free_list(result);
    free(number_one_str);
    free(number_two_str);

    return 0;
}