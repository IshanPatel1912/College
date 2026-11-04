#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

#define HASH_TABLE_SIZE 101

// Hash Table Node for collision resolution (separate chaining)
struct HashNode {
    int key;
    struct HashNode* next;
};

struct HashTable {
    struct HashNode* table[HASH_TABLE_SIZE];
};

struct HashTable* createHashTable() {
    struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// Hash Function (handles negative keys properly)
int hashFunction(int key) {
    int hash = key % HASH_TABLE_SIZE;
    if (hash < 0) {
        hash += HASH_TABLE_SIZE;
    }
    return hash;
}

// Insert key into Hash Table
void insertHash(struct HashTable* ht, int key) {
    int index = hashFunction(key);
    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->key = key;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

// Search key in Hash Table: returns true if found
bool searchHash(struct HashTable* ht, int key) {
    int index = hashFunction(key);
    struct HashNode* curr = ht->table[index];
    while (curr != NULL) {
        if (curr->key == key) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void freeHashTable(struct HashTable* ht) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        struct HashNode* curr = ht->table[i];
        while (curr != NULL) {
            struct HashNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(ht);
}

// Function to check if array B is a subset of array A using Hashing
bool isSubset(int arrA[], int nA, int arrB[], int nB) {
    struct HashTable* ht = createHashTable();

    // Step 1: Insert all elements of array A into hash table
    for (int i = 0; i < nA; i++) {
        insertHash(ht, arrA[i]);
    }

    // Step 2: Search each element of array B in the hash table
    for (int i = 0; i < nB; i++) {
        if (!searchHash(ht, arrB[i])) {
            freeHashTable(ht);
            return false; // Found an element in B that is not in A
        }
    }

    freeHashTable(ht);
    return true; // All elements of B are present in A
}

void printArray(int arr[], int n) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : ", ");
    }
    printf(" }\n");
}

int main() {
    printHeader();

    // Test Case 1: B is a subset of A
    int arrA1[] = {11, 1, 13, 21, 3, 7};
    int arrB1[] = {11, 3, 7, 1};
    int nA1 = sizeof(arrA1) / sizeof(arrA1[0]);
    int nB1 = sizeof(arrB1) / sizeof(arrB1[0]);

    printf("--- Test Case 1 ---\n");
    printf("Array A: "); printArray(arrA1, nA1);
    printf("Array B: "); printArray(arrB1, nB1);
    if (isSubset(arrA1, nA1, arrB1, nB1)) {
        printf(">> Result: Array B IS a subset of Array A.\n");
    } else {
        printf(">> Result: Array B is NOT a subset of Array A.\n");
    }

    // Test Case 2: B is not a subset of A
    int arrA2[] = {10, 5, 2, 23, 19};
    int arrB2[] = {19, 5, 3}; // 3 is not in A2
    int nA2 = sizeof(arrA2) / sizeof(arrA2[0]);
    int nB2 = sizeof(arrB2) / sizeof(arrB2[0]);

    printf("\n--- Test Case 2 ---\n");
    printf("Array A: "); printArray(arrA2, nA2);
    printf("Array B: "); printArray(arrB2, nB2);
    if (isSubset(arrA2, nA2, arrB2, nB2)) {
        printf(">> Result: Array B IS a subset of Array A.\n");
    } else {
        printf(">> Result: Array B is NOT a subset of Array A.\n");
    }

    printf("\n================ COMPLEXITY NOTE ================\n");
    printf(" Time Complexity : O(nA + nB) on average.\n");
    printf(" Space Complexity: O(nA) to store elements of array A.\n");
    printf("=================================================\n");

    return 0;
}
