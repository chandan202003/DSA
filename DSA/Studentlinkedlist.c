#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char usn[10], name[20], branch[10], phno[15]; // Changed phno to char[]
    int sem;
    struct Student *next;
} *new_node, *head, *temp;

void insert(char usn[], char name[], char branch[], int sem, char phno[]) {
    new_node = (struct Student*)malloc(sizeof(struct Student));
    strcpy(new_node->usn, usn);
    strcpy(new_node->name, name);
    strcpy(new_node->branch, branch);
    strcpy(new_node->phno, phno); // Use strcpy for string
    new_node->sem = sem;
    new_node->next = head;
    head = new_node;
}

void display() {
    temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
    } else {
        printf("\nUSN\tName\t\tBranch\tSem\tPhone\n");
        while (temp != NULL) {
            printf("%s\t%s\t\t%s\t%d\t%s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
            temp = temp->next;
        }
    }
}

int main() {
    int choice, sem;
    char usn[10], name[20], branch[10], phno[15];

    while (1) {
        printf("\n1. Insert\n2. Display\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter USN: ");
                scanf("%s", usn);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Branch: ");
                scanf("%s", branch);
                printf("Enter Semester: ");
                scanf("%d", &sem);
                getchar(); // Consume newline before taking phno input
                printf("Enter Phone Number: ");
                scanf("%s", phno); // Read phone number as string
                insert(usn, name, branch, sem, phno);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}