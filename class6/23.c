
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct node {
    element data;
    struct node* link;
} node;

typedef enum { false, true } bool;

void add_element(node** phead, node* new_node) {
    if (*phead == NULL) {
        new_node->link = NULL;
        *phead = new_node;
    } else {
        node* c = NULL;
        node* p = *phead;
        while (p != NULL) {
            if (new_node->data < p->data) {
                if (c == NULL) {
                    new_node->link = *phead;
                    *phead = new_node;
                } else {
                    c->link = new_node;
                    new_node->link = p;
                }
                break;
            }
            c = p;
            p = p->link;
        }
        if (p == NULL) {
            c->link = new_node;
            new_node->link = NULL;
        }
    }
}

void delete_element(node** head, element item) {
    node* p = NULL;
    node* removed = *head;
    while (removed->data != item) {
        p = removed;
        removed = removed->link;
    }
    if (p == NULL)
        *head = (*head)->link;
    else
        p->link = removed->link;
    free(removed);
}

void clear(node** head) {
    node* p = *head;
    while (p != NULL) {
        node* temp = p;
        p = p->link;
        free(temp);
    }
    *head = NULL;
}

int get_length(node* head) {
    int count = 0;
    node* p = head;
    while (p != NULL) {
        count++;
        p = p->link;
    }
    return count;
}

bool is_empty(node* head) {
    return head == NULL;
}

node* create_node(element data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        fprintf(stderr, "메모리에러\n");
        exit(1);
    }
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}
