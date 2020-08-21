/*
    Ques 4.Create a link list by user and give him these following option
            (i)Delete head node.
            (ii)insert new node at head.
            (iii)delete last node
            (iv)insert new node at last.
            (v) delete random node as by user.
            (vi) insert new node at random by user.
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

void traverse()
{
    struct node *temp;
    if(start==NULL)
    {
        printf("List is Empty.\n");
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

void insert_at_begin(int data)
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

void insert_at_end(int data)
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

void insert_at_specified(int pos,int data)
{
    struct node *temp,*prev;
    int c=1;
    struct node *newnode=create(data);
    if(start==NULL)
    {
        start=newnode;
    }
    if(pos==1)
    {
        newnode->next=start;
        start=newnode;
    }
    else{
        temp=prev=start;
        while(temp!=NULL)
        {
            if(c==pos)
            {
                break;
            }
            prev=temp;
            temp=temp->next;
            c++;
        }
        newnode->next=temp;
        prev->next=newnode;
    }
}

void delete_from_begin()
{
    if(start==NULL)
        printf("List is Empty.\n");
    else{
        start=start->next;
        traverse();
    }
}

void delete_from_end()
{
    struct node *temp,*prev;
    if(start==NULL)
        printf("List is Empty.\n");
    if(start->next==NULL)
        {
            start=NULL;
            traverse();
        }
    else{
        temp=start;
        while(temp->next!=NULL)
            {
                prev=temp;
                temp=temp->next;
            }
        prev->next=NULL;
        traverse();
    }
}

void delete_from_specified(int pos)
{
    int c=1;
    struct node *temp,*prev;
    if(start==NULL)
        printf("List is Empty.\n");
    if(start->next==NULL)
        {
            start=NULL;
            traverse();
        }
    else if(pos==1)
    {
        delete_from_begin();
    }
    else{
        temp=start;
        while(temp->next!=NULL)
            {
                if(c==pos)
                    break;
                prev=temp;
                temp=temp->next;
                c++;
            }
        prev->next=temp->next;
        traverse();
    }
}

int main()
{
    int ch,data,pos;
    while(1)
    {
        printf("1.Insert Node at Beginning.\n");
        printf("2.Insert Node at End.\n");
        printf("3.Insert Node at Specified Position.\n");
        printf("4.Delete Node from Beginning.\n");
        printf("5.Delete Node from End.\n");
        printf("6.Delete Node from Specific Position.\n");
        printf("7.Traverse the List.\n");
        printf("8.Exit.\n");
        printf("Enter Your Choice :\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter data to be inserted : ");
                    scanf("%d",&data);
                    insert_at_begin(data);
                break;
            case 2: printf("\nEnter data to be inserted : ");
                    scanf("%d",&data);
                    insert_at_end(data);
                break;
            case 3: printf("\nEnter position where data is to be inserted : ");
                    scanf("%d",&pos);
                    printf("\nEnter data : ");
                    scanf("%d",&data);
                    insert_at_specified(pos,data);
                break;
            case 4: delete_from_begin();
                break;
            case 5: delete_from_end();
                break;
            case 6: printf("\nEnter position from where data is to be deleted : ");
                    scanf("%d",&pos);
                    delete_from_specified(pos);
                break;
            case 7: traverse();
                break;
            case 8: exit(1);
                break;
            default: printf("\nWrong Choice.");
        }
    }
    return 0;
}
