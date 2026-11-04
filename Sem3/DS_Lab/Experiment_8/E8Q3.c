#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// O(N) recursive function to construct BST from preorder traversal
// using value range constraints (min, max)
struct Node* constructBSTUtil(int pre[], int* preIndex, int key, int min, int max, int size) {
    if (*preIndex >= size) {
        return NULL;
    }

    struct Node* root = NULL;

    // If current element is within range, it belongs to this subtree
    if (key > min && key < max) {
        root = newNode(key);
        *preIndex = *preIndex + 1;

        if (*preIndex < size) {
            // All elements in left subtree must be < key
            root->left = constructBSTUtil(pre, preIndex, pre[*preIndex], min, key, size);
        }
        if (*preIndex < size) {
            // All elements in right subtree must be > key
            root->right = constructBSTUtil(pre, preIndex, pre[*preIndex], key, max, size);
        }
    }

    return root;
}

struct Node* constructBST(int pre[], int size) {
    int preIndex = 0;
    return constructBSTUtil(pre, &preIndex, pre[0], INT_MIN, INT_MAX, size);
}

void printInorder(struct Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

void printPreorder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    printHeader();

    // Example preorder sequence
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(pre) / sizeof(pre[0]);

    printf("Input Preorder Sequence: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", pre[i]);
    }
    printf("\n------------------------------------------------------------\n");

    printf("Constructing Binary Search Tree...\n");
    struct Node* root = constructBST(pre, size);
    printf(">> BST successfully constructed!\n\n");

    printf("Verification Traversal Results:\n");
    printf("  1. Inorder Traversal (Must be strictly sorted): \n     ");
    printInorder(root);
    printf("\n\n");

    printf("  2. Preorder of Constructed BST (Matches input): \n     ");
    printPreorder(root);
    printf("\n");

    printf("============================================================\n");
    freeTree(root);
    return 0;
}
