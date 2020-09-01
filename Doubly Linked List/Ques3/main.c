/*
    Ques 3. Insert this array in CLL int arr[]={9,0,4,5,6,7,0,0,6,4};
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

void insert_at_end(int val)
{
    struct node *newnode=createNode(val);
    struct node *temp;
    if(start==NULL)
    {
        start=newnode;
    }
    else{
        temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
    }
}
int main()
{
    int arr[]={9,0,4,5,6,7,0,0,6,4};
    int i,n=sizeof(arr)/sizeof(int);
    for(i=0;i<n;i++)
        insert_at_end(arr[i]);
    traverse();

    return 0;
}
