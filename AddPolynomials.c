//This program adds polynomials of type ax^2+bx+c=0 using a single linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int a;
    int b;
    int c;
    struct node* next;
}*newNode=NULL,*head=NULL,*ptr=NULL;

int sum_a=0,sum_b=0,sum_c=0; //to hld the sums of the respective coefficients

void create() //to create a node for each polynomial
{
    int a,b,c;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter values 'a','b' and 'c'(coefficients of equation ax^2+bx+c=0):");
    scanf("%d%d%d",&a,&b,&c);
    newNode->a=a;
    newNode->b=b;
    newNode->c=c;
    newNode->next=NULL;
}

void read() //to take in the input and simultaneously create a SLL
{
    while(1)
    {
        int ch;
        printf("\nEnter 1 if you want to enter a polynomial else -1:");
        scanf("%d",&ch);
        if(ch==1)
        {
            create(); //calls the create function
            if(head==NULL)
                head=newNode;
            else
            {
                ptr=head;
                while(ptr->next!=NULL)
                    ptr=ptr->next;
                ptr->next=newNode;
            }
        }
        else
        {
           break;
        }
    }
}

void sum() //to add the polynomials
{
     ptr=head;
     while(ptr!=NULL)
     {
         sum_a+=ptr->a;
         sum_b+=ptr->b;
         sum_c+=ptr->c;
         ptr=ptr->next;
     }
}

void main()
{
    read();
    sum();
    printf("\nSum of polynomials= %d x^2 + %d x + %d=0",sum_a,sum_b,sum_c);
}
