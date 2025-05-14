#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node* Create() 
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data (-1 for no data): ");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    printf("Enter the left child of %d\n", x);
    newnode->left = Create();
    printf("Enter the right child of %d\n", x);
    newnode->right = Create();
    return newnode;
}
void preOrder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void InOrder(struct node *root) {
    if (root == NULL) {
        return;
    }     
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}
void PostOrder(struct node *root) {
    if (root == NULL) {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);
}
int main() {
    struct node *root = NULL;
    root = Create();
    printf("\nPreorder Traversal of the tree: ");
    preOrder(root);
    printf("\nInorder Traversal of the tree: ");
    InOrder(root);
    printf("\nPostorder Traversal of the tree: ");
    PostOrder(root);
    printf("\n");
    return 0;
}