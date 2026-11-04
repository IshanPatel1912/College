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

// a. isEmpty(S): Tests whether stack is empty or not
bool isEmpty(struct Node* top) {
    return top == NULL;
}

// b. push(S): Adds new element to the stack
void push(struct Node** top_ref, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = *top_ref;
    *top_ref = new_node;
}

// c. pop(S): Removes top element from the stack
int pop(struct Node** top_ref) {
    if (isEmpty(*top_ref)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct Node* temp = *top_ref;
    int popped_value = temp->data;
    *top_ref = (*top_ref)->next;
    free(temp);
    return popped_value;
}

// d. top(S): Returns value of the top element
int top(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return top->data;
}

// Recursive helper: insert element into sorted stack without any loops
void sortedInsert(struct Node** top_ref, int element) {
    // Base case: Stack is empty or element is greater than top element
    if (isEmpty(*top_ref) || element > top(*top_ref)) {
        push(top_ref, element);
        return;
    }

    // If top is greater, remove top and recurse
    int temp = pop(top_ref);
    sortedInsert(top_ref, element);

    // Put back the top item
    push(top_ref, temp);
}

// Recursive stack sorting function (strictly no loops)
void sortStack(struct Node** top_ref) {
    // Base case: Stack is empty
    if (isEmpty(*top_ref)) {
        return;
    }

    // Remove the top item
    int temp = pop(top_ref);

    // Sort the remaining stack recursively
    sortStack(top_ref);

    // Push the top item back in sorted order
    sortedInsert(top_ref, temp);
}

// Recursive print function without using any loops
void printStackRecursive(struct Node* curr) {
    if (isEmpty(curr)) {
        printf("NULL\n");
        return;
    }
    printf("[%d] -> ", curr->data);
    printStackRecursive(curr->next);
}

// Recursive cleanup
void freeStackRecursive(struct Node** top_ref) {
    if (isEmpty(*top_ref)) return;
    pop(top_ref);
    freeStackRecursive(top_ref);
}

int main() {
    printHeader();

    struct Node* S = NULL;

    printf("Pushing elements to stack: 30, -5, 18, 14, 45\n");
    push(&S, 30);
    push(&S, -5);
    push(&S, 18);
    push(&S, 14);
    push(&S, 45);

    printf("\nOriginal Stack (Top -> Bottom): ");
    printStackRecursive(S);

    // Sort the stack recursively without loops
    sortStack(&S);

    printf("\nSorted Stack   (Top -> Bottom): ");
    printStackRecursive(S);
    printf("============================================================\n");

    freeStackRecursive(&S);
    return 0;
}
