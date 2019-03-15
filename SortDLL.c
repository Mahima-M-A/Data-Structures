//Program to sort a double linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* prev;
    int value;
    struct node* next;
}*newNode=NULL,*head=NULL,*ptr=NULL,*tail=NULL,*lptr=NULL;

void create() //to create a new node
{
    int val;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value:");
    scanf("%d",&val);
    newNode->value=val;
    newNode->next=NULL;
}

void insert() //to create a DLL
{
    if(head==NULL)
    {
        create();
        head=newNode;
        tail=head;
    }
    create();
    tail->next=newNode;
    tail=newNode;
}

void sort() //to sort the created DLL
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

void print() //to print the DLL
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
    printf("\nUnsorted DLL:\n");
    print();
    sort(); //calls the sort function
    printf("\nSorted DLL:\n");
    print();
}
