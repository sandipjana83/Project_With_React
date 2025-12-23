#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create tree recursively
struct Node* createTree() {
    int value;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &value);

    if (value == -1)
        return NULL;

    struct Node *newNode = createNode(value);

    printf("Enter left child of %d:\n", value);
    newNode->left = createTree();

    printf("Enter right child of %d:\n", value);
    newNode->right = createTree();

    return newNode;
}

// Function to print tree in preorder traversal
void preorder(struct Node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    struct Node *root;
    printf("Create the binary tree:\n");
    root = createTree();

    printf("\nPreorder traversal of the tree:\n");
    preorder(root);
    printf("\n");

    return 0;
}
