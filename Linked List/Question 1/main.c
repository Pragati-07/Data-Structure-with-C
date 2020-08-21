/*
    Ques 1.Create link list of node 5 of integer insert data in code not by user.
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *next;
};

struct node *start=NULL;

struct node * create(int val)
{
   struct node *n=(struct node *)malloc(sizeof(struct node));
   n->data=val;
   n->next=NULL;
   return n;
}
void insert(int data)
{
    struct node *newnode=create(data);
    if(start==NULL)
    {
        start=newnode;
    }
    else{
        newnode->next=start;
        start=newnode;
    }
}
void traverse()
{
    struct node *temp;
    if(start==NULL)
    {
        printf("\nList is Empty");
    }
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
int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    traverse();
    return 0;
}
