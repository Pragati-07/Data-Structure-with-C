/*
    Ques 2.Create link list insert data by user up to nodes user want.
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
    int data;
    printf("Enter data (Press CTRL+Z to Stop) : \n");
    while(scanf("%d",&data)>0)
    {
        insert(data);
    }
    traverse();
    return 0;
}
