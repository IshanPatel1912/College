// Implement various functionalities of Queue using Arrays. For example: insertion,
//deletion, front element, rear element etc.
#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int val) {
    if (rear == SIZE - 1) {
        printf("Queue Full!\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = val;
        printf("Inserted %d\n", val);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Empty!\n");
    } else {
        printf("Deleted %d\n", queue[front++]);
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue Empty!\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int getFront() {
    if (front == -1 || front > rear) {
        printf("Queue Empty!\n");
        return -1;
    }
    return queue[front];
}

int getRear() {
    if (front == -1 || front > rear) {
        printf("Queue Empty!\n");
        return -1;
    }
    return queue[rear];
}

int main() {
    int choice, val, result;

    while (1) {
        printf("\n1.Enqueue \n2.Dequeue \n3.Front \n4.Rear \n5.Display \n6.Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input breakdown!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
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
