#include <stdio.h>
#include <stdlib.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// 1. Insert at front
void insertAtFront(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    new_node->prev = NULL;

    if (*head_ref != NULL) {
        (*head_ref)->prev = new_node;
    }

    *head_ref = new_node;
    printf(">> Inserted [%d] at Front.\n", new_data);
}

// 2. Insert after a given node
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf(">> Error: The given previous node cannot be NULL.\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;

    if (prev_node->next != NULL) {
        prev_node->next->prev = new_node;
    }
    prev_node->next = new_node;

    printf(">> Inserted [%d] after [%d].\n", new_data, prev_node->data);
}

// 3. Insert at end
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        printf(">> Inserted [%d] at End (First Node).\n", new_data);
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
    printf(">> Inserted [%d] at End.\n", new_data);
}

// Delete a given node
void deleteNode(struct Node** head_ref, struct Node* del_node) {
    if (*head_ref == NULL || del_node == NULL) {
        return;
    }

    if (*head_ref == del_node) {
        *head_ref = del_node->next;
    }

    if (del_node->next != NULL) {
        del_node->next->prev = del_node->prev;
    }

    if (del_node->prev != NULL) {
        del_node->prev->next = del_node->next;
    }

    printf(">> Deleted node [%d].\n", del_node->data);
    free(del_node);
}

void printList(struct Node* head) {
    struct Node* last = NULL;
    struct Node* curr = head;

    printf("  Forward  : NULL <-> ");
    while (curr != NULL) {
        printf("[%d] <-> ", curr->data);
        last = curr;
        curr = curr->next;
    }
    printf("NULL\n");

    printf("  Backward : NULL <-> ");
    while (last != NULL) {
        printf("[%d] <-> ", last->data);
        last = last->prev;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    printHeader();

    struct Node* head = NULL;

    printf("--- 1. Doubly Linked List Insertions ---\n");
    insertAtFront(&head, 20);
    insertAtFront(&head, 10);
    insertAtEnd(&head, 40);
    insertAfter(head->next, 30); // Insert 30 after 20
    insertAtEnd(&head, 50);

    printf("\n--- Traversal after Insertions ---\n");
    printList(head);

    printf("\n--- 2. Doubly Linked List Deletions ---\n");
    printf("Deleting head node (10):\n");
    deleteNode(&head, head);
    printList(head);

    printf("\nDeleting a middle node (30):\n");
    deleteNode(&head, head->next); // points to 30
    printList(head);

    printf("============================================================\n");
    freeList(head);
    return 0;
}
