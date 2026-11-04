#include <stdio.h>
#include <limits.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

int main() {
    printHeader();

    int n;
    printf("Enter number of elements (minimum 2): ");
    if (scanf("%d", &n) != 1 || n < 2) {
        printf("Error: At least 2 elements are required.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("  Element [%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int minVal = INT_MAX, secondMin = INT_MAX;
    int maxVal = INT_MIN, secondMax = INT_MIN;

    for (int i = 0; i < n; i++) {
        // Find minimum and second minimum
        if (arr[i] < minVal) {
            secondMin = minVal;
            minVal = arr[i];
        } else if (arr[i] < secondMin && arr[i] != minVal) {
            secondMin = arr[i];
        }

        // Find maximum and second maximum
        if (arr[i] > maxVal) {
            secondMax = maxVal;
            maxVal = arr[i];
        } else if (arr[i] > secondMax && arr[i] != maxVal) {
            secondMax = arr[i];
        }
    }

    printf("\n================ Summary ================\n");
    printf("  Array Elements         : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("  Minimum Element        : %d\n", minVal);
    printf("  Maximum Element        : %d\n", maxVal);

    if (secondMin == INT_MAX) {
        printf("  Second Smallest Element: (Not present - all elements equal)\n");
    } else {
        printf("  Second Smallest Element: %d\n", secondMin);
    }

    if (secondMax == INT_MIN) {
        printf("  Second Largest Element : (Not present - all elements equal)\n");
    } else {
        printf("  Second Largest Element : %d\n", secondMax);
    }
    printf("=========================================\n");

    return 0;
}
