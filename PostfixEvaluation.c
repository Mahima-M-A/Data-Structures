//Program to evaluate a valid postfix expression with multiple digits, eg: 30 2 +=32

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define SIZE 50

int stack[SIZE],top=0,flag=0;
char postfix[SIZE];

void push(int ele) //to push each operator
{
    if(top<SIZE-1)
         stack[top++]=ele;
    else
    {
        printf("\nStack overflow");
        flag=1;
    }

}

int pop() //to pop each operator
{
    if(top<0)
    {
        printf("\nStack underflow");
        flag=1;
    }
    else
        return stack[--top];
}

void main() //takes in the input and gives the right output according to the expression's validity
{
    int i=0,x1=0,x2=0,k=0;
    char ch;
    printf("\nEnter a postfix expression each token separated by a space:");
    gets(postfix);
    while(postfix[i]!='\0')
    {
        int l=0,r=0;
        ch=postfix[i];
        if(isdigit(ch))
        {
            for(k=0;postfix[i+k]!=' ';k++)
            {
                r=(r*10)+(postfix[i+k]-48);

                l++;
            }
            i+=l;
            push(r);
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
        {
            x2=pop();
            x1=pop();
            if(ch=='+')
                push(x1+x2);
            if(ch=='-')
                push(x1-x2);
            if(ch=='*')
                push(x1*x2);
            if(ch=='/')
            {
                if(x2==0)
                    printf("\nDivision by zero is not possible!");
                else
                    push(x1/x2);
            }
            if(ch=='^')
                push(pow(x1,x2));
        }
        else if(ch==' '); //if this doesn't work then use else if(ch==' '){}
        else
            flag=1;
        i=i+1;
    }
    if(top==1&&flag!=1)
        printf("\nResult= %d",pop());
    else
    {
        printf("\nInvalid expression!");
        main();
    }
}
