/*
    Ques 1. Create a DLL of 6 nodes insert inputs in your code.
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
    int i,arr[]={4,8,3,2,9,1};
    for(i=0;i<6;i++)
        insert_at_begin(arr[i]);
    traverse();
    return 0;
}
