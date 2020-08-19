/*
Question 3. WAP to create array by user and also use Exponential and Interpolation search.

Time Complexity : O(log n)
*/
#include <stdio.h>
#include <stdlib.h>
int binarySearch(int arr[],int x,int l,int h)
{
    int mid;
    if(l>h)
        return -1;
    mid=(h+l)/2;
    if(arr[mid]==x)
        return mid+1;
    else if(arr[mid]<x)
        return binarySearch(arr,x,mid+1,h);
    else
        return binarySearch(arr,x,l,mid-1);
}
int expoSearch(int arr[],int n,int x)
{
    int i,j;
    i=1;
    while(i<n && arr[i]<x)
    {
        i*=2;
    }
    j=i/2;
    if(i>=n)
    {
        i=n;
    }
    return binarySearch(arr,x,j,i);
}

int interpolationSearch(int arr[],int x,int lo,int hi)
{
    int pos;
    while(lo<=hi && x>=arr[lo] && x<=arr[hi])
    {
        if(lo==hi)
        {
            if(arr[lo]==x)
                return lo+1;
            return -1;
        }
        pos=lo+((hi-lo)/(arr[hi]-arr[lo])*(x-arr[lo]));
        if(arr[pos]==x)
            return pos+1;
        else if(arr[pos]<x)
            return interpolationSearch(arr,x,pos+1,hi);
        else
            return interpolationSearch(arr,x,lo,pos-1);
    }
    return -1;
}
int main()
{
    int n,i,x,index1,index2;
    printf("Enter number of elements to be stored in array : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter Elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nEnter element to be searched : ");
    scanf("%d",&x);
    index1=expoSearch(arr,n,x);
    index2=interpolationSearch(arr,x,0,n-1);
    if(index1==index2)
    {
        if(index1!=-1)
            printf("Found at index %d.",index1);
        else
            printf("Not Found");
    }
    return 0;
}
