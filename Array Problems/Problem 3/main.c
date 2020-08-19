/*
    Problem 3 :  int arr[]={1,2,4,2,3,5,4,7,6,5,8,6,7,6,5,4,5,4,5,4,3,2,1,2,3,4,5,6,7,8,9,0,9,8,9,0,9,8,7,8,7,6,7,6,5,3}
                `   Remove duplicates from above array and print all different elements.
*/
#include <stdio.h>
#include <stdlib.h>
void merge(int arr[],int l,int m,int h)
{
    int i,j,k,b[h-l+1];
    i=l;
    j=m+1;
    k=0;
    while(i<=m && j<=h)
    {
        if(arr[i]<arr[j])
        {
            b[k]=arr[i];
            i++;
        }
        else{
            b[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=m)
    {
        b[k]=arr[i];
        i++;
        k++;
    }
    while(j<=h)
    {
        b[k]=arr[j];
        j++;
        k++;
    }
    k=0;
    for(i=l;i<=h;i++)
    {
        arr[i]=b[k];
        k++;
    }
}
void sort(int arr[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(h+l)/2;
        sort(arr,l,mid);
        sort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
int main()
{
    int i,arr[]={1,2,4,2,3,5,4,7,6,5,8,6,7,6,5,4,5,4,5,4,3,2,1,2,3,4,5,6,7,8,9,0,9,8,9,0,9,8,7,8,7,6,7,6,5,3};
    int n=sizeof(arr)/sizeof(int);
    int prev,j=0;
    sort(arr,0,n-1);
    prev=-1;
    for(i=0;i<n;i++)
    {
        if(arr[i]!=prev)
        {
            arr[j]=arr[i];
            j++;
        }
        prev=arr[i];
    }
    for(i=0;i<j;i++)
        printf("%d ",arr[i]);
    return 0;
}
