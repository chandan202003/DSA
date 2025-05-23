#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
char stack[20];
int top = -1;
void push(char x) {
    stack[++top] = x;
}
char pop() {
    if (top == -1) 
        return -1;
    else 
        return stack[top--];
}
int priority(char x) {
    if (x == '(') 
        return 0;
    else if (x == '+' || x == '-') 
        return 1;
    else if (x == '*' || x == '/') 
        return 2;
    else if (x == '^') 
        return 3;
    return -1;
}
void main() {
    char exp[20], *e, x;
    printf("Enter the infix expression:\n");
    scanf("%s", exp);
    e = exp;
    while (*e != '\0') {
        if (isalnum(*e)) { 
            printf("%c", *e);
        } 
        else if (*e == '(') { 
            push(*e);
        } 
        else if (*e == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        } 
        else { 
            while (top != -1 && priority(stack[top]) >= priority(*e)) {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }
    while (top != -1) {
        printf("%c", pop());
    }
}