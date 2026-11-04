#include <stdio.h>
#include <stdbool.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

bool isFull() {
    return rear == SIZE - 1;
}

bool isEmpty() {
    return (front == -1 || front > rear);
}

void enqueue(int val) {
    if (isFull()) {
        printf(">> [Overflow] Queue is full! Cannot insert %d.\n", val);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = val;
    printf(">> Enqueued: %d (Front: %d, Rear: %d)\n", val, front, rear);
}

int dequeue() {
    if (isEmpty()) {
        printf(">> [Underflow] Queue is empty!\n");
        return -1;
    }
    int val = queue[front++];
    printf(">> Dequeued: %d\n", val);
    if (front > rear) {
        front = rear = -1; // Reset queue
    }
    return val;
}

int getFront() {
    if (isEmpty()) {
        printf(">> Queue is empty!\n");
        return -1;
    }
    return queue[front];
}

int getRear() {
    if (isEmpty()) {
        printf(">> Queue is empty!\n");
        return -1;
    }
    return queue[rear];
}

void display() {
    if (isEmpty()) {
        printf("Queue State: [Empty]\n");
        return;
    }
    printf("Queue State: Front -> ");
    for (int i = front; i <= rear; i++) {
        printf("[%d] ", queue[i]);
    }
    printf("<- Rear\n");
}

int main() {
    printHeader();

    printf("--- Performing Queue Operations ---\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60); // Test Overflow
    display();

    printf("\nFront Element : %d\n", getFront());
    printf("Rear Element  : %d\n\n", getRear());

    dequeue();
    dequeue();
    display();

    printf("\nFront Element : %d\n", getFront());
    printf("Rear Element  : %d\n", getRear());
    printf("============================================================\n");

    return 0;
}
