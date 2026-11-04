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

bool isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

bool isEmpty() {
    return (front == -1);
}

// a. insertFront(): Adds an item at the front of Deque
void insertFront(int val) {
    if (isFull()) {
        printf(">> [Overflow] Deque is Full! Cannot insert %d at front.\n", val);
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }
    deque[front] = val;
    printf(">> Inserted [%d] at Front. (Front: %d, Rear: %d)\n", val, front, rear);
}

// b. insertLast(): Adds an item at the rear of Deque
void insertLast(int val) {
    if (isFull()) {
        printf(">> [Overflow] Deque is Full! Cannot insert %d at rear.\n", val);
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = val;
    printf(">> Inserted [%d] at Rear.  (Front: %d, Rear: %d)\n", val, front, rear);
}

// c. deleteFront(): Deletes an item from the front of Deque
void deleteFront() {
    if (isEmpty()) {
        printf(">> [Underflow] Deque is Empty! Cannot delete from front.\n");
        return;
    }
    int val = deque[front];
    printf(">> Deleted [%d] from Front.\n", val);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

// d. deleteLast(): Deletes an item from the rear of Deque
void deleteLast() {
    if (isEmpty()) {
        printf(">> [Underflow] Deque is Empty! Cannot delete from rear.\n");
        return;
    }
    int val = deque[rear];
    printf(">> Deleted [%d] from Rear.\n", val);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
}

void display() {
    if (isEmpty()) {
        printf("Deque State: [Empty]\n");
        return;
    }
    printf("Deque State: Front -> ");
    int i = front;
    while (1) {
        printf("[%d] ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("<- Rear\n");
}

int main() {
    printHeader();

    printf("--- 1. Testing insertFront and insertLast ---\n");
    insertLast(10);
    insertLast(20);
    insertFront(5);
    insertLast(30);
    insertFront(1);
    display();

    printf("\n--- 2. Testing Overflow ---\n");
    insertLast(99);

    printf("\n--- 3. Testing deleteFront and deleteLast ---\n");
    deleteFront();
    display();
    deleteLast();
    display();

    printf("============================================================\n");
    return 0;
}
