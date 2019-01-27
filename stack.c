//Program to implement an integer stack(push,pop,display) following LIFO

#include<stdio.h>
#include<stdlib.h>
#define SIZE 4

int stack[SIZE];
int top=-1;

int pop();
void push(int ele);
void display();

void main()
{
    int ch;
    int ele;
    while(1)
    {
        printf("\n1.Push,\n2.Pop,\n3.Display,\n-1.Exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter a number:");
            scanf("%d",&ele);
            push(ele); //pushes entered number
            break;
        case 2:
            int popped=pop();
            if(popped!=-1)
            {
                printf("\nPopped element: %d\n",popped); //displays popped number
            }
            break;
        case 3:
            display();
            break;
        case -1:
            exit(0);
            break;
        default:
            printf("\nInvalid choice!\n");
        }
    }
}

//function to push a number into the stack at the rear end

void push(int ele)
{
    if(top==SIZE-1)
        printf("\nStack overflow\n\n");
    else
    {
        top=top+1;
        stack[top]=ele;
    }
}

//function to pop a number from the rear end of the stack

int pop()
{
    int data;
    if(top==-1)
    {
        printf("\nStack underflow\n\n");
        return -1;
    }
    else
    {
        data=stack[top];
        top=top-1;
    }
    return data;
}

void display()
{
    if(top==-1)
    {
        printf("\nStack underflow\n\n");
    }
    else
    {
        printf("Stack contains:\n");
        for(int i=0;i<=top;i++)
            printf("%d\n",stack[i]);
    }
}
