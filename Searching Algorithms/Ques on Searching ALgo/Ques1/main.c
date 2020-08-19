/*
Question 1. Find frequency of 2,3,5 from the following array. (Linear Search)
{1,2,1,2,4,5,3,4,5,6,7,8,7,6,5,4,3,2,3,4,5,6,5,3,2,3,4,5,6,7,8,6,5,4,3,2,2,3,3,4,5,3,2,1,2,3,4,5,6,7,8} one by one.

Time Complexity - O(n)
*/
#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[],int n,int x)
{
    int i,count=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
            count++;
    }
    return count;
}
int main()
{
    int n,i;
    int arr[]={1,2,1,2,4,5,3,4,5,6,7,8,7,6,5,4,3,2,3,4,5,6,5,3,2,3,4,5,6,7,8,6,5,4,3,2,2,3,3,4,5,3,2,1,2,3,4,5,6,7,8};
    n=sizeof(arr)/4;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\nFrequency of 2 in the given array is %d.",linearSearch(arr,n,2));
    printf("\nFrequency of 3 in the given array is %d.",linearSearch(arr,n,3));
    printf("\nFrequency of 5 in the given array is %d.",linearSearch(arr,n,5));
    return 0;
}
