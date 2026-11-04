#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Create a new BST node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert an element into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        printf("  [Notice] Duplicate key %d ignored.\n", value);
    }
    return root;
}

// Search for an element in BST
bool search(struct Node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Find minimum value node in a subtree (used for deletion with two children)
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Delete an element from BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        printf("  [Notice] Key %d not found in tree.\n", key);
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found: handle 3 cases

        // Case 1 & 2: Node with 0 or 1 child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node with 2 children
        // Get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);
        root->data = temp->data; // Copy successor's content to this node
        root->right = deleteNode(root->right, temp->data); // Delete successor
    }
    return root;
}

// Inorder traversal to verify BST structure (should be sorted)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
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

    struct Node* root = NULL;

    // 1. Insertion
    printf("--- 1. Inserting Elements: 50, 30, 20, 40, 70, 60, 80 ---\n");
    int elements[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }

    printf("Inorder Traversal (Sorted): ");
    inorder(root);
    printf("\n\n");

    // 2. Searching
    printf("--- 2. Searching Elements ---\n");
    int keysToSearch[] = {40, 99};
    for (int i = 0; i < 2; i++) {
        int k = keysToSearch[i];
        if (search(root, k)) {
            printf("  -> Element %d is PRESENT in the BST.\n", k);
        } else {
            printf("  -> Element %d is NOT PRESENT in the BST.\n", k);
        }
    }

    // 3. Deletion
    printf("\n--- 3. Deleting Elements ---\n");
    printf("a) Deleting leaf node (20):\n");
    root = deleteNode(root, 20);
    printf("   Inorder: "); inorder(root); printf("\n");

    printf("b) Deleting node with single child (30):\n");
    root = deleteNode(root, 30);
    printf("   Inorder: "); inorder(root); printf("\n");

    printf("c) Deleting node with two children (50 - Root):\n");
    root = deleteNode(root, 50);
    printf("   Inorder: "); inorder(root); printf("\n");

    printf("============================================================\n");
    freeTree(root);
    return 0;
}
