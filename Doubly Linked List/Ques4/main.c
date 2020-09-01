/*
    Ques.4 Create a CLL list by user and give him these following option
        (1) delete random node as by user.
        (2) insert new node at random by user.
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

void insert_at_random(int val,int n)
{
    struct node *newnode=createNode(val);
    struct node *temp;
    if(start==NULL)
        start=newnode;
    else{
        temp=start;
        while(temp->next!=NULL && temp->data!=n)
        {
            temp=temp->next;
        }
        if(temp->prev!=NULL)
        {
            newnode->next=temp;
            newnode->prev=temp->prev;
            temp->prev->next=newnode;
            temp->prev=newnode;
        }
        else{
                newnode->next=temp;
                temp->prev=newnode;
                start=newnode;
            }
        }
}
void delete_from_random(int n)
{
    struct node *temp;
    if(start==NULL)
        printf("\nList is Empty.\n");
    else{
        temp=start;
        while(temp->next!=NULL && temp->data!=n)
            temp=temp->next;
        if(temp->prev->prev!=NULL )
            {
                temp->prev->prev->next=temp;
                temp->prev=temp->prev->prev;
            }
        else if(temp->prev!=NULL)
        {
            start=temp;
        }
        else{
            temp->next->prev=NULL;
            start=temp->next;
        }
    }
    traverse();
}

int main()
{
    int ch,n,val;
    while(1){
    printf("\n1.Insert at random.\n2.Delete from random.\n3.Traverse.\n4.EXIT\nEnter Your Choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1: printf("\nEnter node before you want to insert data : ");
            scanf("%d",&n);
            printf("\nEnter data to insert : ");
            scanf("%d",&val);
            insert_at_random(val,n);
        break;
    case 2: printf("\nEnter node before you want to delete data : ");
            scanf("%d",&n);
            delete_from_random(n);
        break;
    case 3: traverse();
        break;
    case 4: exit(1);
    default :printf("\nWrong Choice");
    }
    }
    return 0;
}
