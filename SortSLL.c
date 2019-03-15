//Program to sort a single linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node* next;
}*newNode=NULL,*head=NULL,*ptr=NULL,*lptr=NULL;

void create() //to create a new node
{
    int val;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value:");
    scanf("%d",&val);
    newNode->value=val;
    newNode->next=NULL;
}

void insert() to create a SLL
{
    if(head==NULL)
    {
        create();
        head=newNode;
    }
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    create();
    ptr->next=newNode;
}

void sort() //to sort the created SLL
{
    int flag=0;
    do
    {
        flag=0;
        int temp=0;
        ptr=head;
        while(ptr->next!=lptr)
        {
            if(ptr->value>ptr->next->value)
            {
                temp=ptr->next->value;
                ptr->next->value=ptr->value;
                ptr->value=temp;
                flag=1;
            }
            ptr=ptr->next;
        }
        lptr=ptr;
    }while(flag);
}

void print() //to print the SLL
{
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->value);
        ptr=ptr->next;
    }
}

void main()
{
    int n;
    printf("\nEnter the total number of elements you want to insert:");
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        insert();
    printf("\nUnsorted SLL:\n");
    print();
    sort();
    printf("\nSorted SLL:\n");
    print();
}
