#include <stdio.h>
#include <stdbool.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

#define SIZE 5

int deque[SIZE];
int front = -1;
int rear = -1;

// c. isEmpty(): Checks whether Deque is empty or not
bool isEmpty() {
    return (front == -1);
}

// d. isFull(): Checks whether Deque is full or not
bool isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

// a. getFront(): Gets the front item from the queue
int getFront() {
    if (isEmpty()) {
        printf(">> Deque is Empty!\n");
        return -1;
    }
    return deque[front];
}

// b. getRear(): Gets the last item from queue
int getRear() {
    if (isEmpty()) {
        printf(">> Deque is Empty!\n");
        return -1;
    }
    return deque[rear];
}

void insertRear(int val) {
    if (isFull()) {
        printf(">> [Overflow] Deque is Full!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = val;
    printf(">> Inserted [%d] at Rear\n", val);
}

void display() {
    if (isEmpty()) {
        printf("Deque State: [Empty]\n");
        return;
    }
    printf("Deque Elements: ");
    int i = front;
    while (1) {
        printf("[%d] ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    printHeader();

    printf("--- Initial State Check ---\n");
    printf("  isEmpty() : %s\n", isEmpty() ? "True" : "False");
    printf("  isFull()  : %s\n\n", isFull() ? "True" : "False");

    printf("--- Inserting 5 Elements to Fill Deque ---\n");
    insertRear(10);
    insertRear(20);
    insertRear(30);
    insertRear(40);
    insertRear(50);
    display();

    printf("\n--- State Check when Full ---\n");
    printf("  isEmpty()  : %s\n", isEmpty() ? "True" : "False");
    printf("  isFull()   : %s\n", isFull() ? "True" : "False");
    printf("  getFront() : %d\n", getFront());
    printf("  getRear()  : %d\n", getRear());
    printf("============================================================\n");

    return 0;
}
