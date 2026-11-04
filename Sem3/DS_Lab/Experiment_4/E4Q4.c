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
    struct Node* next;
};

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = *head_ref; // Points to itself
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != *head_ref) {
        last = last->next;
    }

    last->next = new_node;
    new_node->next = *head_ref; // Maintains circular structure
}

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("The Circular Linked List is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Start (Head) -> ");

    do {
        printf("[%d] -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("(Back to Head: [%d])\n", head->data);
}

void freeCircularList(struct Node** head_ref) {
    if (*head_ref == NULL) return;

    struct Node* current = *head_ref;
    struct Node* next_node;
    do {
        next_node = current->next;
        free(current);
        current = next_node;
    } while (current != *head_ref);

    *head_ref = NULL;
}

int main() {
    printHeader();

    struct Node* head = NULL;

    printf("Inserting nodes into Circular Linked List: 10, 20, 30, 40\n");
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);

    printf("\nTraversing the Circular Linked List:\n");
    printf("------------------------------------------------------------\n");
    traverse(head);
    printf("------------------------------------------------------------\n");

    printf("\nAdding another node: 50\n");
    append(&head, 50);
    printf("Updated Traversal:\n");
    traverse(head);

    freeCircularList(&head);
    return 0;
}
