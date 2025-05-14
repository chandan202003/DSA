#include <stdio.h>
#include <stdlib.h>
// Program 1 Variables
int a1[10][10], d1[10][10], n1;
// Program 2 Variables
int a2[10][10], t2[10][10], n2;
int min(int a, int b) {
return (a < b) ? a : b;
}
void path1() {
int i, j, k;
for (k = 0; k < n1; k++) {
for (i = 0; i < n1; i++) {
for (j = 0; j < n1; j++) {
d1[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);
}
}
}
}
void floyd() {
int i, j;
printf("\n Enter n of vertices (Program 1): ");
scanf("%d", &n1);
printf("\n Enter the cost matrix (Program 1):\n");
for (i = 0; i < n1; i++)
for (j = 0; j < n1; j++) {
scanf("%d", &a1[i][j]);
d1[i][j] = a1[i][j];
}
path1();
printf("\n The final Distance Matrix (Program 1) is :\n");
for (i = 0; i < n1; i++) {
for (j = 0; j < n1; j++) {
printf("%5d", d1[i][j]);
}
printf("\n");
}
}
void path2() {
int i, j, k;
for (k = 0; k < n2; k++) {
for (i = 0; i < n2; i++) {
for (j = 0; j < n2; j++) {
if ((t2[i][j]) || (t2[i][k] && t2[k][j])) t2[i][j] = 1;
}
}
}
}
void Warshall() {
int i, j;
printf("\n Enter n of vertices (Program 2): ");
scanf("%d", &n2);
printf("\n Enter the adjacent matrix (Program 2):\n");
for (i = 0; i < n2; i++)
for (j = 0; j < n2; j++) {
scanf("%d", &a2[i][j]);
t2[i][j] = a2[i][j];
}
path2();
printf("\n The transitive clouser Matrix (Program 2) is :\n");
for (i = 0; i < n2; i++) {
for (j = 0; j < n2; j++) {
printf("%5d", t2[i][j]);
}
printf("\n");
}
}
int main() {
int choice;
while (1) {
printf("\nMenu:\n");
printf("1. Run Program 1 (Floyd Algorithm)\n");
printf("2. Run Program 2 (Transitive Closure)\n");
printf("3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
floyd();
break;
case 2:
Warshall();
break;
case 3:
printf("Exiting program.\n");
return 0;
default:
printf("Invalid choice. Please try again.\n");
}
}
return 0;
}