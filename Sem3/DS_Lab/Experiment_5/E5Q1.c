#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

/* ============================================================
   PART 1: STACK IMPLEMENTATION USING ARRAY
   ============================================================ */
#define MAX_SIZE 5

struct ArrayStack {
    int items[MAX_SIZE];
    int top;
};

void initArrayStack(struct ArrayStack* s) {
    s->top = -1;
}

bool isArrayStackFull(struct ArrayStack* s) {
    return s->top == MAX_SIZE - 1;
}

bool isArrayStackEmpty(struct ArrayStack* s) {
    return s->top == -1;
}

void pushArray(struct ArrayStack* s, int val) {
    if (isArrayStackFull(s)) {
        printf("  [Array Stack] Overflow! Cannot push %d.\n", val);
        return;
    }
    s->items[++(s->top)] = val;
    printf("  [Array Stack] Pushed %d (Top index: %d)\n", val, s->top);
}

int popArray(struct ArrayStack* s) {
    if (isArrayStackEmpty(s)) {
        printf("  [Array Stack] Underflow! Stack is empty.\n");
        return -1;
    }
    return s->items[(s->top)--];
}

int peekArray(struct ArrayStack* s) {
    if (isArrayStackEmpty(s)) {
        printf("  [Array Stack] Stack is empty.\n");
        return -1;
    }
    return s->items[s->top];
}

void displayArrayStack(struct ArrayStack* s) {
    if (isArrayStackEmpty(s)) {
        printf("  [Array Stack] Stack is empty.\n");
        return;
    }
    printf("  [Array Stack] Top -> ");
    for (int i = s->top; i >= 0; i--) {
        printf("[%d] ", s->items[i]);
    }
    printf("\n");
}

/* ============================================================
   PART 2: STACK IMPLEMENTATION USING LINKED LIST
   ============================================================ */
struct Node {
    int data;
    struct Node* next;
};

bool isListEmpty(struct Node* top) {
    return top == NULL;
}

void pushList(struct Node** top_ref, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("  [List Stack] Heap Overflow! Cannot allocate memory.\n");
        return;
    }
    new_node->data = value;
    new_node->next = *top_ref;
    *top_ref = new_node;
    printf("  [List Stack] Pushed %d onto Linked List Stack\n", value);
}

int popList(struct Node** top_ref) {
    if (isListEmpty(*top_ref)) {
        printf("  [List Stack] Underflow! Stack is empty.\n");
        return -1;
    }
    struct Node* temp = *top_ref;
    int popped_value = temp->data;
    *top_ref = (*top_ref)->next;
    free(temp);
    return popped_value;
}

int peekList(struct Node* top) {
    if (isListEmpty(top)) {
        printf("  [List Stack] Stack is empty.\n");
        return -1;
    }
    return top->data;
}

void displayListStack(struct Node* top) {
    if (isListEmpty(top)) {
        printf("  [List Stack] Stack is empty.\n");
        return;
    }
    printf("  [List Stack] Top -> ");
    struct Node* curr = top;
    while (curr != NULL) {
        printf("[%d] -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    printHeader();

    // 1. Array Stack Testing
    printf("============================================================\n");
    printf("           1. TESTING STACK USING ARRAY                     \n");
    printf("============================================================\n");
    struct ArrayStack aStack;
    initArrayStack(&aStack);

    pushArray(&aStack, 10);
    pushArray(&aStack, 20);
    pushArray(&aStack, 30);
    pushArray(&aStack, 40);
    pushArray(&aStack, 50);
    pushArray(&aStack, 60); // Overflow test
    displayArrayStack(&aStack);

    printf("  Top Element (Peek): %d\n", peekArray(&aStack));
    printf("  Popped: %d\n", popArray(&aStack));
    printf("  Popped: %d\n", popArray(&aStack));
    displayArrayStack(&aStack);

    // 2. Linked List Stack Testing
    printf("\n============================================================\n");
    printf("        2. TESTING STACK USING LINKED LIST                  \n");
    printf("============================================================\n");
    struct Node* lStack = NULL;

    pushList(&lStack, 100);
    pushList(&lStack, 200);
    pushList(&lStack, 300);
    displayListStack(lStack);

    printf("  Top Element (Peek): %d\n", peekList(lStack));
    printf("  Popped: %d\n", popList(&lStack));
    displayListStack(lStack);

    while (!isListEmpty(lStack)) {
        popList(&lStack);
    }
    printf("------------------------------------------------------------\n");

    return 0;
}
