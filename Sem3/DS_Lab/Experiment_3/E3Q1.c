#include <stdio.h>
#include <stdlib.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

int main() {
    printHeader();

    // 1. Pointer to an Array
    printf("------------------------------------------------------------\n");
    printf(" Part 1: Pointer to an Array (int (*p)[4])\n");
    printf("------------------------------------------------------------\n");
    int a[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int (*p)[4] = a; // Pointer to an array of 4 integers

    printf("2D Array elements accessed via Pointer to Array (*(*(p + i) + j)):\n");
    for (int i = 0; i < 3; i++) {
        printf("  Row %d: ", i);
        for (int j = 0; j < 4; j++) {
            printf("%3d ", *(*(p + i) + j));
        }
        printf("\n");
    }

    // 2. Array of Pointers
    printf("\n------------------------------------------------------------\n");
    printf(" Part 2: Array of Pointers (int *arr[3])\n");
    printf("------------------------------------------------------------\n");
    int *arr[3]; // Array of 3 integer pointers (each points to dynamically allocated row)

    for (int i = 0; i < 3; i++) {
        arr[i] = (int *)malloc(4 * sizeof(int));
        if (arr[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        for (int j = 0; j < 4; j++) {
            arr[i][j] = a[i][j]; // Copy values
        }
    }

    printf("2D Array elements accessed via Array of Pointers (arr[i][j]):\n");
    for (int i = 0; i < 3; i++) {
        printf("  arr[%d] (Address: %p) -> ", i, (void *)arr[i]);
        for (int j = 0; j < 4; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < 3; i++) {
        free(arr[i]);
    }
    printf("\nDynamically allocated row memory successfully freed.\n");

    return 0;
}
