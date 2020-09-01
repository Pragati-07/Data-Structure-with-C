/*
   Ques 5. Create a method which returns number of nodes in DLL.
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

int nodes_in_list()
{
    struct node *t;
    int c=0;
    if(start==NULL)
        return c;
    t=start;
    while(t->next!=start)
    {
        t=t->next;
        c++;
    }
    return c+1;
}

int main()
{
    int data;
    printf("Enter data (Press CTRL+Z to stop) : \n");
    while(scanf("%d",&data)>0)
    {
        insert_begin(data);
    }
    traverse();
    printf("\nNumber of nodes in DLL : %d ",nodes_in_list());
    return 0;
}
