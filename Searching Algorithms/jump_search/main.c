/*
    Jump Search

Input :  First Line : contains n-number of elements in array and x-element to be searched separated by space
         Second Line : n space separated values of array
Output : return -1 if element not present in array or return index where element is present.

Time Complexity : O(n^(1/2))
Space Complexity : O(1)
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int jumpSearch(int arr[],int n,int x)
{
    int i,prev,steps;
    prev=0;
    i=steps=sqrt(n);
    while(i<n && arr[i]<x)
    {
        prev=i;
        i+=steps;
    }
    if(i>n){
    if(arr[n-1]<x)
        return -1;
    else
        i=n-1;
    }
    while(arr[prev]<x)
    {
        prev++;
        if(prev==i)
            break;
    }
    if(arr[prev]==x)
        return prev+1;
    return -1;

}

int main()
{
    int n,x,i,index;
    scanf("%d%d",&n,&x);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    index=jumpSearch(arr,n,x);
    if(index==-1)
        printf("\nNot Found");
    else
        printf("\nFound at index %d",index);
    return 0;
}
