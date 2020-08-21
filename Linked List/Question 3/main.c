/*
    Ques.3 insert this array in a link list.
            int arr[]={9,0,4,5,6,7,0,0,6,4};

*/
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node * create(int value)
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=value;
    n->next=NULL;
    return n;
}
void insert(int data)
{
    struct node *temp;
    struct node *newnode=create(data);
    if(start==NULL)
    {
        start=newnode;
    }
    else{
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void traverse()
{
    struct node *temp;
    if(start==NULL)
    {
        printf("\nList is Empty.");
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
    int i;
    int arr[]={9,0,4,5,6,7,0,0,6,4};
    int n=sizeof(arr)/sizeof(int);
    for(i=0;i<n;i++)
    {
        insert(arr[i]);
    }
    traverse();
    return 0;
}
