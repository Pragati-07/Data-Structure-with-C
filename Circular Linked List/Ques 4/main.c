/*
    Ques 4. Create a CLL list by user and give him these following option
            (1) delete random node as by user.
            (2) insert new node at random by user.
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node* start=NULL;

struct node* createnode(int val)
{
    struct node * n=(struct node *)malloc(sizeof(struct node));
    n->data=val;
    n->next=NULL;
    return n;
};

void traverse()
{
    struct node *curr;
    if(start==NULL)
    {
        printf("\nList is Empty.\n");
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

void insert_at_random(int val,int pos)
{
    struct node *newnode=createnode(val);
    struct node *t,*p;
    int c=1;
    if(start==NULL)
    {
        newnode->next=newnode;
        start=newnode;
    }
    else if(pos==1)
    {
        t=start;
        while(t->next!=start)
            t=t->next;
        t->next=newnode;
        newnode->next=start;
        start=newnode;
    }
    else{
        t=p=start;
        while(t->next!=start)
        {
            if(c==pos)
                break;
            p=t;
            t=t->next;
            c++;
        }
        if(t->next==start)
        {
            t->next=newnode;
            newnode->next=start;
        }
        else{
            newnode->next=t;
            p->next=newnode;
        }
    }

}
void delete_from_random(int pos)
{
    struct node *t,*p;
    int c=1;
    if(start==NULL)
        printf("\nList is Empty.\n");
    else if(pos==1)
    {
        if(start==start->next)
        {
            start=NULL;
        }
        else{
            t=start;
        while(t->next!=start)
        {
            t=t->next;
        }
        start=start->next;
        t->next=start;
        }
    }
    else{
        t=p=start;
        while(t->next!=start)
        {
            if(c==pos)
                break;
            p=t;
            t=t->next;
            c++;
        }
        p->next=t->next;
    }
    traverse();
}
int main()
{
    int data,pos,n;
    while(1){
    printf("1.Insert Node at random position.\n2.Delete node from random position.\n3.Traverse\n4.Exit.");
    printf("\nEnter your choice : \n");
    scanf("%d",&n);
    switch(n)
    {
    case 1: printf("\nEnter data and its position : \n");
            scanf("%d%d",&data,&pos);
            insert_at_random(data,pos);
            break;
    case 2: printf("\nEnter position of node to delete :\n");
            scanf("%d",&pos);
            delete_from_random(pos);
            break;
    case 3: traverse();
            break;
    case 4: exit(0);
    default: printf("\nWrong Choice.\n");
    }
    }
    return 0;
}
