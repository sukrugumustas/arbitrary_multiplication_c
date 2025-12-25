#ifndef ARBITRARY_MULTIPLICATION_LINKED_LIST_H
#define ARBITRARY_MULTIPLICATION_LINKED_LIST_H

typedef struct node {
    int digit;
    struct node *next;
} Node;

Node *create_node(int digit);
void free_list(Node *head);
void push_front(Node **head, int digit);
void append_node(Node **head, Node **tail, int digit);
void print_list(const Node *head);
Node *copy_list(const Node *src);

#endif //ARBITRARY_MULTIPLICATION_LINKED_LIST_H