/*
    Exponential Search

Input :  First Line : contains n-number of elements in array and x-element to be searched separated by space
         Second Line : n space separated values of array
Output : return -1 if element not present in array or return index where element is present.

Time Complexity : O(log n)
Space Complexity : O(1)
*/
#include <stdio.h>
#include <stdlib.h>
#define MIN(X,Y) (((X)<(Y))? (X):(Y))
int binarySearch(int arr[],int x,int l,int h)
{
    int mid;
    while(l<=h)
    {
        mid=(h+l)/2;
        if(arr[mid]==x)
            return mid+1;
        if(arr[mid]<x)
            l=mid+1;
        else
            h=mid-1;
    }
    return -1;
}
int expoSearch(int arr[],int n,int x)
{
    int i;
    i=1;
    while(i<n && arr[i]<=x)
    {
        i=i*2;
    }
    return binarySearch(arr,x,i/2,MIN(i,n));

}
int main()
{
    int n,x,i,index;
    scanf("%d%d",&n,&x);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    index=expoSearch(arr,n,x);
    if(index==-1)
        printf("\nNot Found");
    else
        printf("\nFound at index %d",index);
    return 0;
}
