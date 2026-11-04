#include <stdio.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    printHeader();

    int n;
    printf("Enter array size: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int original[n], arrBubble[n], arrInsert[n], arrSelect[n];
    printf("Enter %d array elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("  Element [%d]: ", i + 1);
        scanf("%d", &original[i]);
        arrBubble[i] = original[i];
        arrInsert[i] = original[i];
        arrSelect[i] = original[i];
    }

    printf("\nOriginal Array: ");
    printArray(original, n);

    // Bubble Sort
    bubbleSort(arrBubble, n);
    printf("\n--- Bubble Sort Result ---\n");
    printArray(arrBubble, n);

    // Insertion Sort
    insertionSort(arrInsert, n);
    printf("\n--- Insertion Sort Result ---\n");
    printArray(arrInsert, n);

    // Selection Sort
    selectionSort(arrSelect, n);
    printf("\n--- Selection Sort Result ---\n");
    printArray(arrSelect, n);

    return 0;
}
