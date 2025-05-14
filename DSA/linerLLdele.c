#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
}*newnode, *head = NULL, *tail = NULL, *temp,*prevnode;
void create() {
    int value;
    newnode = (struct node *)malloc(sizeof(struct node)); 
    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter the value: ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = NULL;
}
void insert() {
    create();
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}
void delbeg(){
    temp=head;
    head=head->next;
    free(temp);
}
void delEnd(){
    temp=head;
    while(temp->next!=NULL)
    {
        prevnode=temp;
        temp=temp->next;
    }
    free(temp);
}
void display() {
    printf("The elements in the linked list are:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int choice;
    while (1) {
        printf("1. Insert an element\n");
        printf("2. Delete an element in beggining\n");
        printf("3. Delete an element at end:\n");
        printf("4. Display the linked list\n");
        printf("5. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delbeg();
                break;
            case 3:
                delEnd();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}