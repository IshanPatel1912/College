#include <stdio.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    printHeader();

    int num1, num2;
    printf("Enter two numbers (separated by space): ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("\n--- Before Swapping ---\n");
    printf("  Variable num1: %d  (Stored at address: %p)\n", num1, (void *)&num1);
    printf("  Variable num2: %d  (Stored at address: %p)\n", num2, (void *)&num2);

    // Call swap by passing addresses of variables
    swap(&num1, &num2);

    printf("\n--- After Swapping (via swap(&num1, &num2)) ---\n");
    printf("  Variable num1: %d\n", num1);
    printf("  Variable num2: %d\n", num2);
    printf("------------------------------------------------------------\n");

    return 0;
}
