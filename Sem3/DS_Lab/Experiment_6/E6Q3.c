#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

#define MAX 200

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

bool isEmpty() {
    return top == -1;
}

// Check if open and close brackets match
bool isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')') return true;
    if (character1 == '{' && character2 == '}') return true;
    if (character1 == '[' && character2 == ']') return true;
    return false;
}

// Function to check if expression has balanced brackets
bool areBracketsBalanced(const char* exp) {
    top = -1; // reset stack

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        // If opening bracket, push to stack
        if (ch == '{' || ch == '(' || ch == '[') {
            push(ch);
        }
        // If closing bracket
        else if (ch == '}' || ch == ')' || ch == ']') {
            if (isEmpty()) {
                return false; // unmatched closing bracket
            }
            char openBracket = pop();
            if (!isMatchingPair(openBracket, ch)) {
                return false; // mismatched pair
            }
        }
    }

    // If stack is empty, all brackets were matched
    return isEmpty();
}

int main() {
    printHeader();

    // Test cases from the Lab Manual
    const char* test1 = "[( )]{ }{[( )( )]( )}";
    const char* test2 = "[( ])";

    printf("--- Test Case 1 (From Manual) ---\n");
    printf("Expression: %s\n", test1);
    printf("Result    : %s\n", areBracketsBalanced(test1) ? "Balanced" : "Not Balanced");

    printf("\n--- Test Case 2 (From Manual) ---\n");
    printf("Expression: %s\n", test2);
    printf("Result    : %s\n", areBracketsBalanced(test2) ? "Balanced" : "Not Balanced");

    // Interactive Test Case
    printf("\n--- Test Case 3 (Interactive Input) ---\n");
    char userExp[MAX];
    printf("Enter an expression to check: ");
    if (fgets(userExp, sizeof(userExp), stdin) != NULL) {
        userExp[strcspn(userExp, "\r\n")] = '\0';
        if (strlen(userExp) > 0) {
            printf("Expression: %s\n", userExp);
            printf("Result    : %s\n", areBracketsBalanced(userExp) ? "Balanced" : "Not Balanced");
        }
    }

    printf("============================================================\n");
    return 0;
}
