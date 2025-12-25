#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

Node *create_node(const int digit) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    node->digit = digit;
    node->next = NULL;
    return node;
}

void free_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
}

void push_front(Node **head, const int digit) {
    Node *new_node = create_node(digit);
    new_node->next = *head;
    *head = new_node;
}

void append_node(Node **head, Node **tail, const int digit) {
    Node *new_node = create_node(digit);
    if (*head == NULL) {
        *head = new_node;
        *tail = new_node;
    } else {
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

static void print_recursive(const Node *node) {
    if (node == NULL) return;
    print_recursive(node->next);
    fprintf(stdout, "%d", node->digit);
}

void print_list(const Node *head) {
    if (head == NULL) {
        printf("0");
        return;
    }
    print_recursive(head);
}

Node *copy_list(const Node *src) {
    Node *new_head = NULL, *new_tail = NULL;
    for (const Node *ptr = src; ptr != NULL; ptr = ptr->next) {
        append_node(&new_head, &new_tail, ptr->digit);
    }
    return new_head;
}