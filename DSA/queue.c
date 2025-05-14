#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
void Cenqueue(int item);
void Cdequeue();
void Cdisplay();
int front=-1;
int rear=-1;
int q[SIZE];
 
int main()
{
	int item,ch;
	while(1)
	{
    	printf("\n 1. CEnqueue. \n 2. CDequeue. \n 3. CDisplay. \n 4. Exit.");
    	printf("\n Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
    	{
        	case 1:
                    printf("\n Enter element to be inserted: ");
                    scanf("%d",&item);
                	Cenqueue(item);
                	break;
        	case 2:
                    Cdequeue();
                    break;
        	case 3:
                    Cdisplay();
                    break;
        	case 4:
                    exit(0);
            default:
                    printf("Invalid choice");
    	}
	}
 
	return 0;
}
void Cenqueue(int item)
{
    if(front==(rear+1)%SIZE)
	{
        printf("Queue is Full!");
	}
	else
	{
        rear=(rear+1)%SIZE;
        q[rear]=item;
        if(front==-1)
    	{
            front=front+1;
    	}
	}
}
void Cdequeue()
{
	int del;
    if(front==-1)
	{
        printf("\nQueue is Empty...");
	}
	else
	{
     del=q[front];
     printf("\n Element deleted is %d",del);
     if(front==rear)
 	{
         front=-1,rear=-1;
 	}
 	else
 	{
         front=(front+1)%SIZE;
 	}
	}
}
 
void Cdisplay()
{
	int i;
	if (front == -1) {
        printf("\nQueue is empty");
	}
	else {
        printf("\nThe Elements in the Queue are: \n");
    	for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d\t", q[i]);
    	}
        printf("%d\t", q[i]); // Print the last element
	}
}
