/*
Question 6. {1,2,3,4,5,6,7,8,9,10,13,15,18,19,23,25,27,31,35,42,47,49}
WAP where user may choose which type of searching is required i.e.
Press 1 for Linear Search
Press 2 for Binary Search
Press 3 for Jump Search

Time Complexity : O(n)
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MIN(X,Y) ((X)<(Y))?(X):(Y)

int linearSearch(int arr[],int n,int x)
{
    int i;
    for(i=0;i<n;i++)
        if(arr[i]==x)
            return i+1;
    return -1;
}
int binarySearch(int arr[],int x,int l,int h)
{
    int mid;
    if(l>h)
        return -1;
    mid=(l+h)/2;
    if(arr[mid]==x)
        return mid+1;
    else if(arr[mid]<x)
        return binarySearch(arr,x,mid+1,h);
    else
        return binarySearch(arr,x,l,mid-1);
}
int jumpSearch(int arr[],int n,int x)
{
    int i,steps,prev,j;
    steps=sqrt(n);
    i=prev=0;
    while(i<n && arr[i]<x)
    {
        prev=i;
        i=i+steps;
    }
    i=MIN(i,n-1);
    for(j=prev;j<=i;j++)
    {
        if(arr[j]>=x)
            break;
    }
    if(arr[j]==x)
        return j+1;
    else
        return -1;
}
int main()
{
    int n,x,ch,index;
    int arr[]={1,2,3,4,5,6,7,8,9,10,13,15,18,19,23,25,27,31,35,42,47,49};
    n=sizeof(arr)/4;
    printf("Enter Element to be searched : ");
    scanf("%d",&x);
    while(1)
    {
        printf("\nPress 1 for Linear Search");
        printf("\nPress 2 for Binary Search");
        printf("\nPress 3 for Jump Search");
        printf("\nPress 4 to search another element");
        printf("\nPress 5 to Exit");
        printf("\nChoose your Option : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: index=linearSearch(arr,n,x);
                    if(index!=-1)
                        printf("\nFound at index %d.\n",index);
                    else
                        printf("\nNot Found\n");
                    break;
            case 2: index=binarySearch(arr,x,0,n-1);
                    if(index!=-1)
                        printf("\nFound at index %d.\n",index);
                    else
                        printf("\nNot Found\n");
                    break;
            case 3: index=jumpSearch(arr,n,x);
                    if(index!=-1)
                        printf("\nFound at index %d.\n",index);
                    else
                        printf("\nNot Found\n");
                    break;
            case 4: main();
            case 5: exit(1);
            default: printf("\nWrong Choice\n");
        }
    }
    return 0;
}
