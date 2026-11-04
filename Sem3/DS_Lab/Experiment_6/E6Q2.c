#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

#define MAX 100

// Stack for operands
double valStack[MAX];
int valTop = -1;

void pushVal(double val) {
    if (valTop < MAX - 1) {
        valStack[++valTop] = val;
    }
}

double popVal() {
    if (valTop >= 0) {
        return valStack[valTop--];
    }
    printf("Error: Stack underflow during evaluation!\n");
    return 0;
}

// Evaluate postfix expression where tokens can be separated by spaces
double evaluatePostfix(const char* exp) {
    valTop = -1;
    char buffer[256];
    strncpy(buffer, exp, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    char* token = strtok(buffer, " \t\r\n");
    while (token != NULL) {
        // If token is an operator and length is 1 (or handle negative numbers)
        if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/' || token[0] == '^')) {
            double op2 = popVal();
            double op1 = popVal();
            double res = 0;

            switch (token[0]) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/':
                    if (op2 == 0) {
                        printf("Error: Division by zero!\n");
                        return 0;
                    }
                    res = op1 / op2;
                    break;
                case '^': res = pow(op1, op2); break;
            }
            pushVal(res);
        } else {
            // Token is a number
            double num = atof(token);
            pushVal(num);
        }
        token = strtok(NULL, " \t\r\n");
    }

    return popVal();
}

int main() {
    printHeader();

    // Problem 2(a)
    const char* exp1 = "2 3 1 * + 9 -";
    printf("--- Case 1 (Manual Problem 2a) ---\n");
    printf("Expression: %s\n", exp1);
    double res1 = evaluatePostfix(exp1);
    printf("Result    : %.2f (Expected: -4)\n", res1);

    // Problem 2(b)
    const char* exp2 = "2 2 + 2 / 5 * 7 +";
    printf("\n--- Case 2 (Manual Problem 2b) ---\n");
    printf("Expression: %s\n", exp2);
    double res2 = evaluatePostfix(exp2);
    printf("Result    : %.2f (Expected: 17)\n", res2);

    // Interactive Case
    printf("\n--- Case 3 (Interactive Postfix Evaluation) ---\n");
    printf("Enter space-separated postfix expression (e.g. 10 5 + 3 *): ");
    char userExp[256];
    if (fgets(userExp, sizeof(userExp), stdin) != NULL) {
        userExp[strcspn(userExp, "\r\n")] = '\0';
        if (strlen(userExp) > 0) {
            double resUser = evaluatePostfix(userExp);
            printf("Result    : %.2f\n", resUser);
        }
    }

    printf("============================================================\n");
    return 0;
}
