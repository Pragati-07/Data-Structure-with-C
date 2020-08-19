/*
    Problem 1 : Write a programm to swap elements in an array condition swapping elements are twice to other means
                if first elements is 2 then swap it with 4 only ........
                (Hint:- first sort that and then swap)
                int arr[]={1,2,3,6,7,4,18,912,14,11,22,13,26,15,30,17,34};
*/
#include <stdio.h>
#include <stdlib.h>
void merge(int a[],int l,int m,int h)
{
    int b[h-l];
    int i=l;
    int j=m+1;
    int k=0;
    while(i<=m && j<=h)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=m)
    {
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=h)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    k=0;
    for(i=l;i<=h;i++)
    {
        a[i]=b[k];
        k++;
    }
}
void mergeSort(int arr[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(h+l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
int search(int a[],int start,int n,int s)
{
    int i;
    for(i=start;i<=n;i++)
    {
        if(a[i]==s)
            return i;
    }
    return -1;
}
int main()
{
    int i,index,prev,temp;
    int arr[]={1,2,3,6,7,4,18,912,14,11,22,13,26,15,30,17,34};
    int n=sizeof(arr)/sizeof(int);
    mergeSort(arr,0,n-1);
    prev=0;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    for(i=0;i<n;i++)
    {
        index=search(arr,prev+1,n,2*arr[i]);
        if(index!=-1)
            {
                prev=index;
                temp=arr[i];
                arr[i]=arr[index];
                arr[index]=temp;
            }
    }
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
