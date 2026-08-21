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

int getFront() {
    if (isEmpty()) {
        printf("Queue Empty!\n");
        return -1;
    }
    return deque[front];
}

int getRear() {
    if (isEmpty()) {
        printf("Queue Empty!\n");
        return -1;
    }
    return deque[rear];
}

void display() {
    if (isEmpty()) {
        printf("Queue Empty!\n");
        return;
    }

    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, val, result;

    while (1) {
        printf("\n1.Insert Front \n2.Insert Rear \n3.Front \n4.Rear \n5.Display \n6.Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input breakdown!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertLast(val);
                break;
            case 3:
                result = getFront();
                if (result != -1) {
                    printf("Front Element: %d\n", result);
                }
                break;
            case 4:
                result = getRear();
                if (result != -1) {
                    printf("Rear Element: %d\n", result);
                }
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
