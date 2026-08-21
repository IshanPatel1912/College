#include <stdio.h>
#include <stdbool.h>

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

void insertFront(int val) {
    if (isFull()) {
        printf("Overflow! Deque is Full.\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else if (front == 0) {
        front = SIZE - 1;
    }
    else {
        front--;
    }

    deque[front] = val;
    printf("Inserted %d at front. (Front: %d, Rear: %d)\n", val, front, rear);
}

void insertLast(int val) {
    if (isFull()) {
        printf("Overflow! Deque is Full.\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else if (rear == SIZE - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = val;
    printf("Inserted %d at last. (Front: %d, Rear: %d)\n", val, front, rear);
}

void deleteFront() {
    if (isEmpty()) {
        printf("Underflow! Deque is Empty.\n");
        return;
    }

    printf("Deleted %d from front.\n", deque[front]);

    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (front == SIZE - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

void deleteLast() {
    if (isEmpty()) {
        printf("Underflow! Deque is Empty.\n");
        return;
    }

    printf("Deleted %d from rear.\n", deque[rear]);

    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (rear == 0) {
        rear = SIZE - 1;
    }
    else {
        rear--;
    }
}

void display() {
    if (isEmpty()) {
        printf("Deque is Empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;
    while (true) {
        printf("%d ", deque[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- Double Ended Queue Operations --- \n");
        printf("1. Insert Front\n2. Insert Last\n3. Delete Front\n4. Delete Last\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input type. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value to insert at last: ");
                scanf("%d", &val);
                insertLast(val);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
