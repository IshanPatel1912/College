#include <stdio.h>
#include <stdlib.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

struct Node {
    int val;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// 1. Insert at the front of the list
void insertAtFront(struct Node** head_ref, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head_ref;
    *head_ref = newNode;
    printf(">> Inserted [%d] at the front.\n", value);
}

// 2. Insert after a given node with target value
void insertAfter(struct Node* head, int targetVal, int newValue) {
    struct Node* curr = head;
    while (curr != NULL && curr->val != targetVal) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf(">> Target node with value %d not found in the list!\n", targetVal);
        return;
    }

    struct Node* newNode = createNode(newValue);
    newNode->next = curr->next;
    curr->next = newNode;
    printf(">> Inserted [%d] after node [%d].\n", newValue, targetVal);
}

// 3. Insert at the end of the list
void insertAtEnd(struct Node** head_ref, int value) {
    struct Node* newNode = createNode(value);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        printf(">> Inserted [%d] at the end (first node).\n", value);
        return;
    }

    struct Node* curr = *head_ref;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
    printf(">> Inserted [%d] at the end.\n", value);
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* curr = head;
    while (curr != NULL) {
        printf("[%d]", curr->val);
        if (curr->next != NULL) printf(" -> ");
        curr = curr->next;
    }
    printf(" -> NULL\n");
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

    printf("Demonstrating all 3 insertion methods:\n");
    printf("------------------------------------------------------------\n");

    // a. At front
    printf("(a) Insertion at Front:\n");
    insertAtFront(&head, 15);
    insertAtFront(&head, 10);
    insertAtFront(&head, 5);
    printf("Current List: ");
    printList(head);

    // b. After a given node
    printf("\n(b) Insertion After a Given Node:\n");
    insertAfter(head, 10, 12); // Insert 12 after 10
    printf("Current List: ");
    printList(head);

    // c. At end
    printf("\n(c) Insertion at End:\n");
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 25);
    printf("Current List: ");
    printList(head);

    printf("------------------------------------------------------------\n");
    printf("Final Linked List: ");
    printList(head);
    printf("============================================================\n");

    freeList(head);
    return 0;
}
