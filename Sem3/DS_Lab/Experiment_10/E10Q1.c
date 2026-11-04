#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

#define MAX 1000

// 2D Hash table:
// has[X][0] = 1 if +X is present
// has[X][1] = 1 if -X is present
bool has[MAX + 1][2];

// Insert elements of array into the hash table in O(1) time each
void insert(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (abs(a[i]) > MAX) {
            printf("Warning: Element %d exceeds MAX limit (%d), ignored.\n", a[i], MAX);
            continue;
        }
        if (a[i] >= 0) {
            has[a[i]][0] = true;
        } else {
            has[abs(a[i])][1] = true;
        }
    }
}

// Search if X is present in O(1) time
bool search(int X) {
    if (abs(X) > MAX) {
        return false;
    }
    if (X >= 0) {
        return has[X][0];
    } else {
        return has[abs(X)][1];
    }
}

int main() {
    printHeader();

    // Example array from lab manual: contains negative and positive numbers
    int a[] = {-1, 9, -5, -8, -5, -2};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Input Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("Hash table constructed using 2D Direct Index Mapping (has[MAX+1][2]).\n\n");

    insert(a, n);

    // Test cases
    int testKeys[] = {-5, 9, -2, 7, -8, 15};
    int numTests = sizeof(testKeys) / sizeof(testKeys[0]);

    printf("--- Direct O(1) Search Results ---\n");
    for (int i = 0; i < numTests; i++) {
        int key = testKeys[i];
        if (search(key)) {
            printf("  Query: %3d -> PRESENT\n", key);
        } else {
            printf("  Query: %3d -> NOT PRESENT\n", key);
        }
    }

    // Interactive query
    printf("\n--- Interactive Query ---\n");
    int userQuery;
    printf("Enter a number to search in O(1) time: ");
    if (scanf("%d", &userQuery) == 1) {
        if (search(userQuery)) {
            printf("  Result: %d is PRESENT in the array.\n", userQuery);
        } else {
            printf("  Result: %d is NOT PRESENT in the array.\n", userQuery);
        }
    }

    printf("============================================================\n");
    return 0;
}
