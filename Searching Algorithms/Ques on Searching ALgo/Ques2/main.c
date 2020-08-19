/*
Question 2. {1,2,3,4,5,6,7,8,9,10,13,15,18,19,23,25,27,31,35,42,47,49}
Find elements taking input from user.Use binary search and check your answer using jump search.
Time Complexity : 0(n^1/2)
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int binarySearch(int arr[],int x,int l,int h)
{
    if(h<l)
        return -1;
    int mid=(l+h)/2;
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
    i=0;
    while(i<n && arr[i]<x)
    {
        prev=i;
        i+=steps;
    }
    if(i>=n)
    {
        i=n-1;
        if(arr[i]>x)
            return -1;
    }
    for(j=prev+1;j<=i;j++)
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
    int n,x,index1,index2,ch;
    int arr[]={1,2,3,4,5,6,7,8,9,10,13,15,18,19,23,25,27,31,35,42,47,49};
    n=sizeof(arr)/4;
    printf("Enter number to be searched : ");
    scanf("%d",&x);
    index1=binarySearch(arr,x,0,n-1);
    if(index1!=-1)
            printf("Found at index %d.",index1);
        else
            printf("Not Found");
    printf("\nPress 1 to check answer with Jump Sort or Press any other digit to exit : ");
    scanf("%d",&ch);
    if(ch==1)
    {
        index2=jumpSearch(arr,n,x);
        if(index2!=-1)
            printf("Found at index %d.",index1);
        else
            printf("Not Found");
    }

    return 0;
}

