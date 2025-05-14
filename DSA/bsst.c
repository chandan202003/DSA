#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
void inorder();
int main() {
    // Create nodes manually
    struct Node* p1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p4 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p5 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p6 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p7 = (struct Node*)malloc(sizeof(struct Node));

    // Assign data
    p1->data = 2;
    p2->data = 3;
    p3->data = 4;
    p4->data = 5;
    p5->data = 6;
    p6->data = 8;

    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    p3->left =p5;
    p3->right = p6;

    p4->left = NULL;
    p4->right = p5;

    p5->left = p3;
    p5->right = p6;

    p6->left = NULL;
    p6->right = NULL;

    for(int i=p1;i<=p6;i++)
    {
        if(indegree(i)==0)
        printf(i);
        else
        printf("The topological order is :\n");
    }
return 0;
}
