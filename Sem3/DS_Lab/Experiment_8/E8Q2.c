#include <stdio.h>
#include <stdlib.h>

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

// Create a new binary tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// a. Pre-order Traversal: Root -> Left -> Right
void printPreorder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

// b. In-order Traversal: Left -> Root -> Right
void printInorder(struct Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

// c. Post-order Traversal: Left -> Right -> Root
void printPostorder(struct Node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
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

    /*
            Constructing following Binary Tree:
                        1
                      /   \
                     2     3
                    / \   / \
                   4   5 6   7
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("--- Tree Structure Constructed ---\n");
    printf("            1          \n");
    printf("          /   \\       \n");
    printf("         2     3       \n");
    printf("        / \\   / \\     \n");
    printf("       4   5 6   7     \n");
    printf("------------------------------------------------------------\n");

    printf("\n(a) Pre-order Traversal  [Root -> Left -> Right]:\n    ");
    printPreorder(root);
    printf("\n");

    printf("\n(b) In-order Traversal   [Left -> Root -> Right]:\n    ");
    printInorder(root);
    printf("\n");

    printf("\n(c) Post-order Traversal [Left -> Right -> Root]:\n    ");
    printPostorder(root);
    printf("\n");

    printf("============================================================\n");
    freeTree(root);
    return 0;
}
