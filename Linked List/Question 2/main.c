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
    int n,data;
    printf("Enter number of nodes in the list : ");
    scanf("%d",&n);
    printf("Enter data : \n");
    while(n--)
    {
        scanf("%d",&data);
        insert(data);
    }
    traverse();
    return 0;
}
