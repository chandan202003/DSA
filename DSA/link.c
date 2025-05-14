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
void insertbeg() {
    create();
    if (head == NULL) {
        head = tail = newnode;
        newnode->next = head;
        head = newnode; 
    }
}
void insertend() {
    create();
    if (head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}
void insertpos() {
    int pos, i;
    if (head == NULL) {
        printf("No list found. Cannot insert at a position.\n");
        return;
    }
    create();
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos == 1) { 
        newnode->next = head;
        head = newnode;
        return;
    }
    temp = head;
    for (i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position out of range.\n");
            return;
        }
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    if (newnode->next == NULL) {
        tail = newnode;
    }
}
void deletebeg() {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}
void deleteend() {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    temp = head;
    while (temp->next != NULL) {
        tail = temp;
        temp = temp->next;
    }
    if (temp == head) {
        head = tail = NULL;
    } else {
        tail->next = NULL;
    }
    free(temp);
}
void display() {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
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
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Display the linked list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertbeg();
                break;
            case 2:
                insertend();
                break;
            case 3:
                insertpos();
                break;
            case 4:
                deletebeg();
                break;
            case 5:
                deleteend();
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}