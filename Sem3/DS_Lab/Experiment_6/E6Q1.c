#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

#define MAX 200

// Stack for characters
char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';
}

int isEmpty() {
    return top == -1;
}

// Function to return precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Check associativity: '^' is right-associative (returns 1 for right, 0 for left)
int isRightAssociative(char op) {
    if (op == '^') return 1;
    return 0;
}

// Check if character is alphanumeric operand
int isOperand(char c) {
    return isalnum(c);
}

// Convert Infix to Postfix
void infixToPostfix(const char* infix, char* postfix) {
    top = -1;
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isspace(c)) {
            continue; // Skip whitespace
        }

        if (isOperand(c)) {
            postfix[k++] = c;
            postfix[k++] = ' '; // add space for clean readability
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
                postfix[k++] = ' ';
            }
            if (!isEmpty() && peek() == '(') {
                pop(); // discard '('
            }
        }
        else { // Operator encountered
            while (!isEmpty() && peek() != '(' &&
                  ((precedence(peek()) > precedence(c)) ||
                   (precedence(peek()) == precedence(c) && !isRightAssociative(c)))) {
                postfix[k++] = pop();
                postfix[k++] = ' ';
            }
            push(c);
        }
    }

    // Pop remaining operators in stack
    while (!isEmpty()) {
        char op = pop();
        if (op != '(') {
            postfix[k++] = op;
            postfix[k++] = ' ';
        }
    }

    if (k > 0 && postfix[k - 1] == ' ') {
        k--; // remove trailing space
    }
    postfix[k] = '\0';
}

int main() {
    printHeader();

    char postfix[MAX];

    // 1. Example from manual: a + b * (c ^ d - e) ^ (f + g * h) - i
    const char* manualExp = "a + b * (c ^ d - e) ^ (f + g * h) - i";
    printf("--- Test Case 1 (From Lab Manual) ---\n");
    printf("Infix Expression   : %s\n", manualExp);
    infixToPostfix(manualExp, postfix);
    printf("Postfix Expression : %s\n", postfix);

    // 2. User Input option
    printf("\n--- Test Case 2 (Interactive Input) ---\n");
    char userInfix[MAX];
    printf("Enter an infix expression (e.g. (A+B)*(C-D)): ");
    if (fgets(userInfix, sizeof(userInfix), stdin) != NULL) {
        userInfix[strcspn(userInfix, "\r\n")] = '\0';
        if (strlen(userInfix) > 0) {
            infixToPostfix(userInfix, postfix);
            printf("Postfix Expression : %s\n", postfix);
        }
    }
    printf("============================================================\n");

    return 0;
}
