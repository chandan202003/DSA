#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to insert a node into the BST
struct node* Insert(struct node *root, int x) {
    if (root == NULL) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }

    if (x < root->data) {
        root->left = Insert(root->left, x);
    } else {
        root->right = Insert(root->right, x);
    }
    
    return root;
}

// Function to create a BST by taking multiple inputs
struct node* Create() {
    struct node *root = NULL;
    int x;

    printf("Enter numbers to insert into BST (-1 to stop):\n");
    while (1) {
        scanf("%d", &x);
        if (x == -1) break;  // Stop when -1 is entered
        root = Insert(root, x);
    }

    return root;
}

// Preorder Traversal (Root -> Left -> Right)
void preOrder(struct node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// Inorder Traversal (Left -> Root -> Right) - **Sorted Order in BST**
void InOrder(struct node *root) {
    if (root == NULL) return;
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

// Postorder Traversal (Left -> Right -> Root)
void PostOrder(struct node *root) {
    if (root == NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    struct node *root = NULL;
    root = Create();

    printf("\nPreorder Traversal of the BST: ");
    preOrder(root);

    printf("\nInorder Traversal of the BST (Sorted Order): ");
    InOrder(root);

    printf("\nPostorder Traversal of the BST: ");
    PostOrder(root);

    printf("\n");
    return 0;
}
