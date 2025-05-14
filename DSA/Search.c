#include <stdio.h>
#include<stdlib.h>
void LSearch(); 
void BSearch();
int a[10];
int n, key;
int main() {
    int choice;
    while (1) {
        printf("\n\tMENU");
        printf("\n\t1. LINEAR SEARCH");
        printf("\n\t2. BINARY SEARCH");
        printf("\n\t3. EXIT");
        printf("\n\tEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                LSearch();
                break;
            case 2:
                BSearch();
                break;
            case 3:
                return 0;
            default:
                printf("\nInvalid choice! Please enter 1, 2, or 3.\n");
        }
    }
    return 0;
}
void LSearch() {
    int i;
    printf("\n\tLINEAR SEARCH...");
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    printf("\nEnter the array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\nEnter the element to be searched: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("\nElement %d is found at position %d", key, i + 1);
            exit(1);
        }
    }
        printf("\nElement %d is not found", key);
}
void BSearch() {
    int low, mid, high, i;
    printf("\n\tBINARY SEARCH...");
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);   
    printf("\nEnter the array elements in ascending order:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\nEnter the element to be searched: ");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key == a[mid]) {
            printf("\nElement %d is found at position %d", key, mid + 1);
            exit(1);        }
        else if (key > a[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
        printf("\nElement %d is not found", key);
}
