/*
    Ques 2.Create a CLL take input from users.
*/
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next,*prev;
};
struct node *start=NULL;

struct node * createNode(int val)
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=val;
    n->next=n->prev=NULL;
    return n;
}

void traverse()
{
    struct node *temp;
    if(start==NULL)
        printf("\nList is Empty.");
    else{
        temp=start;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void insert_at_begin(int val)
{
    struct node *newnode=createNode(val);
    if(start==NULL)
    {
        start=newnode;
    }
    else{
        newnode->next=start;
        start->prev=newnode;
        start=newnode;
    }
}
int main()
{
    int data;
    printf("\nEnter data in Doubly Linked List :(Press CTRL+Z to stop)\n");
    while(scanf("%d",&data)>0)
    {
        insert_at_begin(data);
    }
    traverse();
    return 0;
}
