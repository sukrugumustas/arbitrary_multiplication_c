#include <ctype.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "panic.h"
#include "text_util.h"

char *strip(char *input);
char *trim_zero(char *stripped, char *buffer);

char *take_input(const int number_index) {
    fprintf(stdout, "Please enter number %d:\n", number_index);

    char *buffer = NULL;
    size_t capacity = 0;

    if (getline(&buffer, &capacity, stdin) == -1) {
        terminate(buffer, ERR_NO_INPUT);
    }

    char *stripped = strip(buffer);
    char *cleaned = trim_zero(stripped, buffer);

    free(buffer);
    return cleaned;
}

bool is_zero(const char *input) {
    return strcmp(input, "0") == 0;
}

bool check_and_strip_sign(const char **input) {
    bool is_negative = false;
    if (**input == '+' || **input == '-') {
        is_negative = **input == '-';
        (*input)++;
    }
    return is_negative;
}

char *strip(char *input) {
    if (!input || *input == '\0') {
        terminate(input, ERR_NO_INPUT);
        return NULL;
    }

    char *end = input + strlen(input) - 1;
    while (end >= input && isspace(*end)) {
        *end = '\0';
        end--;
    }

    char *start = input;
    while (*start && isspace(*start)) {
        start++;
    }

    if (*start == '\0') {
        terminate(input, ERR_NO_INPUT);
        return NULL;
    }

    return start;
}

char *trim_zero(char *stripped, char *buffer) {
    char *p = stripped;
    char sign = '\0';

    if (*p == '-' || *p == '+') {
        sign = *p;
        p++;
    }

    if (!isdigit(*p)) {
        terminate(buffer, ERR_INVALID_INPUT);
        return NULL;
    }

    while (*p == '0') p++;

    if (*p == '\0') {
        char *res = strdup("0");
        if (!res) {
            terminate(buffer, ERR_MEMORY_LEAK);
            return NULL;
        }
        return res;
    }

    const char *start = p;
    while (*p != '\0') {
        if (!isdigit(*p)) {
            terminate(buffer, ERR_INVALID_INPUT);
            return NULL;
        }
        p++;
    }

    size_t length = p - start;
    const bool is_negative = sign == '-';
    char *res = malloc(sizeof(char) * (length + (is_negative ? 2 : 1)));

    if (!res) {
        terminate(buffer, ERR_MEMORY_LEAK);
        return NULL;
    }

    if (is_negative) {
        res[0] = '-';
        memcpy(res + 1, start, length);
        res[length + 1] = '\0';
    } else {
        memcpy(res, start, length);
        res[length] = '\0';
    }

    return res;
}