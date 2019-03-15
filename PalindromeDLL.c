//Program to check if the entered word is a palindrome using double linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    char ch;
    struct node *next;
}*newNode=NULL,*head=NULL,*tail=NULL,*ptr=NULL,*lptr=NULL;

void create(char chr) //to create anode for each character
{
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->next=NULL;
    newNode->prev=NULL;
    newNode->ch=chr;
}

void read() //to input a word and simultaneously create the DLL
{
    char word[25];
    printf("Enter a word:");
    scanf("%s",word);
    for(int i=0;word[i]!='\0';i++)
    {
        char chr=word[i];
        create(chr); //calling create function
        if(head==NULL)
        {
            head=newNode;
            tail=head;
        }
        else
        {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
}

void pal() //to check if it is a palindrome
{
    int flag=1;
    ptr=head;
    lptr=tail;
    while(ptr!=lptr)
    {
        if(ptr->ch==lptr->ch)
        {
            ptr=ptr->next;
            lptr=lptr->prev;
        }
        else
        {
            flag=0;
            break;
        }
    }
    if(flag==0)
        printf("Not a palindrome");
    else
        printf("Palindrome");
}

void main()
{
    read();
    pal();
}
