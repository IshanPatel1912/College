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

void printList(struct Node* head) {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d", curr->val);
        if (curr->next != NULL) printf(" => ");
        curr = curr->next;
    }
    printf("\n");
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

    int sizeA, sizeB, value;
    struct Node *list_A = NULL, *tailA = NULL;
    struct Node *list_B = NULL, *tailB = NULL;

    printf("--- Input for Sorted List A ---\n");
    printf("Enter number of elements for List A: ");
    if (scanf("%d", &sizeA) != 1 || sizeA < 0) return 1;

    for (int i = 0; i < sizeA; i++) {
        printf("  Enter element %d (in ascending order): ", i + 1);
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (list_A == NULL) {
            list_A = newNode;
            tailA = newNode;
        } else {
            tailA->next = newNode;
            tailA = newNode;
        }
    }

    printf("\n--- Input for Sorted List B ---\n");
    printf("Enter number of elements for List B: ");
    if (scanf("%d", &sizeB) != 1 || sizeB < 0) return 1;

    for (int i = 0; i < sizeB; i++) {
        printf("  Enter element %d (in ascending order): ", i + 1);
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (list_B == NULL) {
            list_B = newNode;
            tailB = newNode;
        } else {
            tailB->next = newNode;
            tailB = newNode;
        }
    }

    printf("\n------------------------------------------------------------\n");
    printf("List A: ");
    printList(list_A);

    printf("List B: ");
    printList(list_B);
    printf("------------------------------------------------------------\n");

    // Merge logic using dummy node
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    struct Node* p1 = list_A;
    struct Node* p2 = list_B;

    while (p1 != NULL && p2 != NULL) {
        if (p1->val <= p2->val) {
            tail->next = p1;
            p1 = p1->next;
        } else {
            tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
    }

    if (p1 != NULL) {
        tail->next = p1;
    } else {
        tail->next = p2;
    }

    struct Node* merged_list = dummy.next;

    printf("\nMerged Sorted List: ");
    printList(merged_list);
    printf("------------------------------------------------------------\n");

    freeList(merged_list);
    return 0;
}
