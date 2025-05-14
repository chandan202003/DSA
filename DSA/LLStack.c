#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
} *newnode, *top,*temp;
void push() {
    int value;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d", &value);
    newnode->data = value;
    if (top == NULL) {
        newnode->data = value;
        newnode->next = NULL;
        top = newnode;
    } else {
        newnode->data = value;
        newnode->next = top;
        top = newnode;
    }
}
void pop(){
    if (top == NULL) {
        printf("The stack is empty.\n");
    } else {
        temp=top;
        printf("The popped element is %d.\n", top->data);
        top = top->next;
        free(temp);
    }
}
void display() {
    if (top == NULL) {
        printf("The stack is empty.\n");
    } else{
        temp = top;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
int main() {
    int choice;
    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}