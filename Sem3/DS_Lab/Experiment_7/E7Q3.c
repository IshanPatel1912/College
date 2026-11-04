#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

// Node represents an element with a value and an associated priority
// (Higher priority number indicates higher service priority)
struct PQNode {
    int data;
    int priority;
    struct PQNode* next;
};

struct PQNode* createNode(int data, int priority) {
    struct PQNode* newNode = (struct PQNode*)malloc(sizeof(struct PQNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

bool isEmpty(struct PQNode* head) {
    return head == NULL;
}

// Enqueue element according to priority (descending order of priority)
void enqueue(struct PQNode** head, int data, int priority) {
    struct PQNode* newNode = createNode(data, priority);

    // If list is empty or new node has higher priority than head
    if (*head == NULL || priority > (*head)->priority) {
        newNode->next = *head;
        *head = newNode;
        printf(">> Enqueued [%d] (Priority: %d) at Front\n", data, priority);
        return;
    }

    // Traverse list to find position
    struct PQNode* curr = *head;
    while (curr->next != NULL && curr->next->priority >= priority) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    printf(">> Enqueued [%d] (Priority: %d)\n", data, priority);
}

// Dequeue element with highest priority (always at head)
int dequeue(struct PQNode** head) {
    if (isEmpty(*head)) {
        printf(">> [Underflow] Priority Queue is empty!\n");
        return -1;
    }

    struct PQNode* temp = *head;
    int val = temp->data;
    int p = temp->priority;
    *head = (*head)->next;
    free(temp);
    printf(">> Dequeued Highest Priority Element: [%d] (Priority: %d)\n", val, p);
    return val;
}

// Peek highest priority element
void peek(struct PQNode* head) {
    if (isEmpty(head)) {
        printf(">> Priority Queue is empty!\n");
        return;
    }
    printf(">> Highest Priority Element on Top: [%d] (Priority: %d)\n", head->data, head->priority);
}

// Display Priority Queue
void display(struct PQNode* head) {
    if (isEmpty(head)) {
        printf("Priority Queue: [Empty]\n");
        return;
    }

    printf("Priority Queue: Top -> ");
    struct PQNode* curr = head;
    while (curr != NULL) {
        printf("[Val: %d | Pri: %d]", curr->data, curr->priority);
        if (curr->next != NULL) printf(" -> ");
        curr = curr->next;
    }
    printf(" -> End\n");
}

void freePQ(struct PQNode** head) {
    while (!isEmpty(*head)) {
        dequeue(head);
    }
}

int main() {
    printHeader();

    struct PQNode* pq = NULL;

    printf("--- Enqueueing Elements with (Value, Priority) ---\n");
    enqueue(&pq, 10, 1);
    enqueue(&pq, 40, 4);
    enqueue(&pq, 20, 2);
    enqueue(&pq, 50, 5);
    enqueue(&pq, 30, 3);

    printf("\n--- Display Priority Queue (Ordered by Priority) ---\n");
    display(pq);

    printf("\n--- Peeking Highest Priority ---\n");
    peek(pq);

    printf("\n--- Dequeue Operations (Highest Priority Removed First) ---\n");
    dequeue(&pq);
    dequeue(&pq);
    display(pq);

    printf("============================================================\n");
    freePQ(&pq);
    return 0;
}
