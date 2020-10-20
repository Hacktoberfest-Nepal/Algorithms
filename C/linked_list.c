#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct LinkedList LinkedList;

void print_list(LinkedList* list);
void push_back(LinkedList* list, int value);
void push_front(LinkedList* list, int value);
void pop_back(LinkedList* list);
void pop_front(LinkedList* list);
void clear_list(LinkedList* list);

// Represents a node of a linked list
struct Node {
    int value;
    struct Node* next;
};

// A wrapper for a linked list node
struct LinkedList {
    Node* head;
};

// Prints the values of all the nodes in the list
void print_list(LinkedList* list) {
    if (list->head == NULL)
        return;

    Node* iter = list->head;
    while (iter != NULL) {
        printf("%d ", iter->value);
        iter = iter->next;
    }
    printf("\n");
}

// Pushes a node to the back
void push_back(LinkedList* list, int value) {
    if (list->head == NULL) {
        list->head = malloc(sizeof(Node));
        list->head->value = value;
        return;
    }

    Node* iter = list->head;

    while (iter->next != NULL) {
        iter = iter->next;
    }

    iter->next = malloc(sizeof(Node));
    iter->next->value = value;
    iter->next->next = NULL;
}

// Pushes a node to the front
void push_front(LinkedList* list, int value) { 
    if (list->head == NULL) {
        list->head = malloc(sizeof(Node));
        list->head->value = value;
        list->head->next = NULL;
        return;
    }
    
    Node* new_element  = malloc(sizeof(Node));
    new_element->value = value;
    new_element->next = list->head;
    list->head = new_element;
}

// Pops a node from the back
void pop_back(LinkedList* list) {
    Node* iter = list->head;
    if (iter == NULL)
        return;

    if (iter->next == NULL) {
        free(iter);
        list->head = NULL;
        return;
    }

    while (iter->next->next != NULL) {
        iter = iter->next;
    }

    free(iter->next);
    iter->next = NULL;
}

// Pops a node from the front
void pop_front(LinkedList* list) {
    if (list->head == NULL)
        return;

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        return;
    }

    Node* first = list->head;
    list->head = first->next;
    free(first);
}

// Frees all the memory of the list
void clear_list(LinkedList* list) {
    Node* iter = list->head;

    if (iter == NULL)
        return;

    Node* next = iter->next;

    while (next != NULL) {
        free(iter);
        iter = next;
        next = iter->next;
    }

    free(iter);
    list->head = NULL;
}

int main(void) {
    LinkedList list = {
        .head = NULL,
    };

    push_front(&list, 51);
    push_front(&list, 1);
    pop_front(&list);
    push_front(&list, 125);

    print_list(&list);

    clear_list(&list);

    return 0;
}

