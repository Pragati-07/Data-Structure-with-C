/*
    Ques1.  Create a CLL of 6 nodes insert inputs in your code.
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;

struct node* create_newnode(int val)
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=val;
    n->next=NULL;
    return n;
}

void traverse()
{
    struct node *curr;
    if(start==NULL)
    {
        printf("\nList is Empty");
    }
    else{
        curr=start;
        while(curr->next!=start)
        {
            printf("%d ",curr->data);
            curr=curr->next;
        }
        printf("%d\n",curr->data);
    }
}

void insert_begin(int value)
{
        struct node *newnode=create_newnode(value);
        struct node *curr;
        if(start==NULL)
        {
            newnode->next=newnode;
            start=newnode;
        }
        else{
            curr=start;
            while(curr->next!=start)
            {
                curr=curr->next;
            }
            curr->next=newnode;
            newnode->next=start;
            start=newnode;
        }
}

int main()
{
    int arr[]={10,78,5,90,45,20};
    int i;
    for(i=0;i<6;i++)
    {
        insert_begin(arr[i]);
    }
    traverse();
    return 0;
}
