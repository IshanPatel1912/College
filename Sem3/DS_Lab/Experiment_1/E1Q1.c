#include <stdio.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    printHeader();

    int n, target;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("  Element [%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter target element to search: ");
    scanf("%d", &target);

    // Linear Search
    printf("\n--- Performing Linear Search ---\n");
    int linIdx = linearSearch(arr, n, target);
    if (linIdx != -1) {
        printf("  [Linear Search] Element %d found at index %d (position %d).\n", target, linIdx, linIdx + 1);
    } else {
        printf("  [Linear Search] Element %d not found in the array.\n", target);
    }

    // Binary Search requires sorted array
    int sortedArr[n];
    for (int i = 0; i < n; i++) {
        sortedArr[i] = arr[i];
    }
    bubbleSort(sortedArr, n);

    printf("\n--- Performing Binary Search ---\n");
    printf("Sorted array for Binary Search: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sortedArr[i]);
    }
    printf("\n");

    int binIdx = binarySearch(sortedArr, n, target);
    if (binIdx != -1) {
        printf("  [Binary Search] Element %d found at index %d (position %d) in sorted array.\n", target, binIdx, binIdx + 1);
    } else {
        printf("  [Binary Search] Element %d not found in the array.\n", target);
    }

    return 0;
}
