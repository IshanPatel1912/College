#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

struct Queue {
    struct Node *front;
    struct Node *rear;
};

void initQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(struct Queue* q) {
    return q->front == NULL;
}

void enqueue(struct Queue* q, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf(">> [Heap Overflow] Memory allocation failed!\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf(">> Enqueued [%d] to Linked List Queue\n", val);
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf(">> [Underflow] Queue is empty!\n");
        return -1;
    }

    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    printf(">> Dequeued [%d]\n", val);
    return val;
}

int getFront(struct Queue* q) {
    if (isEmpty(q)) {
        printf(">> Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}

int getRear(struct Queue* q) {
    if (isEmpty(q)) {
        printf(">> Queue is empty!\n");
        return -1;
    }
    return q->rear->data;
}

void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue State: [Empty]\n");
        return;
    }
    printf("Queue State: Front -> ");
    struct Node* curr = q->front;
    while (curr != NULL) {
        printf("[%d]", curr->data);
        if (curr->next != NULL) printf(" -> ");
        curr = curr->next;
    }
    printf(" <- Rear\n");
}

void freeQueue(struct Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}

int main() {
    printHeader();

    struct Queue q;
    initQueue(&q);

    printf("--- Performing Linked List Queue Operations ---\n");
    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);
    enqueue(&q, 400);
    display(&q);

    printf("\nFront Element : %d\n", getFront(&q));
    printf("Rear Element  : %d\n\n", getRear(&q));

    dequeue(&q);
    dequeue(&q);
    display(&q);

    printf("\nFront Element : %d\n", getFront(&q));
    printf("Rear Element  : %d\n", getRear(&q));
    printf("============================================================\n");

    freeQueue(&q);
    return 0;
}
