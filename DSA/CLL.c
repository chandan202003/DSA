#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
} *newnode, *head = NULL, *tail = NULL, *temp;
void create() {
    int value;
    newnode = (struct node *)malloc(sizeof(struct node)); 
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter the value: ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = NULL;
}
void insertBeg(){
    create();
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        tail->next = head;
    } else {
        newnode->next = head;
        head = newnode;
        tail->next = head;
    }
}
void insertEnd(){
    create();
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        tail->next = head;
    } else {
        tail->next = newnode;
        tail = newnode;
        tail->next = head;
    }
}
void insertatPos(){
    int pos, i = 1;
    create();
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    temp = head;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void deleteBeg(){
    if (head == NULL) {
        printf("The linked list is empty.\n");
    } else {
        temp = head;
        head = head->next;
        tail->next = head;
        free(temp);
    }
}
void deleteEnd(){
    if (head == NULL) {
        printf("The linked list is empty.\n");
    } else {
        temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head;
        free(tail);
        tail = temp;
    }
}
void display() {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    printf("The elements in the circular linked list are:\n");
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main() {
    int choice;
    while (1) {
        printf("1. Insert an element at Begging\n");
        printf("2. Insert an element at End\n");
        printf("3. Insert an element at any Position\n");
        printf("4. Delete an element at Begging\n");
        printf("5. Delete an element at End\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertBeg();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                insertatPos();
                break;
            case 4:
                deleteBeg();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Exiting the program \n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}