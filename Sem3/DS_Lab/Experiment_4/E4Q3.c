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
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("Empty List (NULL)\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("[%d]", temp->data);
        if (temp->next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

// a. Delete from the beginning
void deleteFromBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf(">> Underflow: List is empty, cannot delete.\n");
        return;
    }
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    printf(">> Deleted [%d] from beginning.\n", temp->data);
    free(temp);
}

// b. Delete from the end
void deleteFromEnd(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf(">> Underflow: List is empty, cannot delete.\n");
        return;
    }
    if ((*head_ref)->next == NULL) {
        printf(">> Deleted [%d] from end (was only node).\n", (*head_ref)->data);
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf(">> Deleted [%d] from end.\n", temp->data);
    free(temp);
}

// c. Delete from the middle (by 1-based position)
void deleteFromMiddle(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf(">> Underflow: List is empty.\n");
        return;
    }
    if (position == 1) {
        deleteFromBeginning(head_ref);
        return;
    }

    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf(">> Position %d is out of range.\n", position);
        return;
    }

    prev->next = temp->next;
    printf(">> Deleted [%d] from position %d.\n", temp->data, position);
    free(temp);
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
    int n, val;

    printf("Enter number of nodes to create initial list (e.g., 5): ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    struct Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        printf("  Enter data for node %d: ", i + 1);
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("\nInitial Linked List: ");
    printList(head);
    printf("------------------------------------------------------------\n");

    // a. Delete from beginning
    printf("\n(a) Delete from Beginning:\n");
    deleteFromBeginning(&head);
    printf("List after deletion: ");
    printList(head);

    // b. Delete from end
    printf("\n(b) Delete from End:\n");
    deleteFromEnd(&head);
    printf("List after deletion: ");
    printList(head);

    // c. Delete from middle
    int pos;
    printf("\n(c) Delete from Middle:\n");
    printf("Enter position to delete: ");
    if (scanf("%d", &pos) == 1) {
        deleteFromMiddle(&head, pos);
        printf("List after deletion: ");
        printList(head);
    }

    printf("============================================================\n");
    freeList(head);
    return 0;
}
