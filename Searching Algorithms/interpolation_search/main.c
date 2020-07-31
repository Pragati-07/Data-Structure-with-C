/*
    Interpolation Search

Input :  First Line : contains n-number of elements in array and x-element to be searched separated by space
         Second Line : n space separated values of array
Output : return -1 if element not present in array or return index where element is present.

Time Complexity : O(loglog n)
Space Complexity : O(1)
*/
#include <stdio.h>
#include <stdlib.h>
int interpoSearch(int arr[],int x,int lo,int hi)
{
    int pos;
    while(hi>=lo && x>=arr[lo] && x<=arr[hi])
    {
        if(lo==hi)
        {
            if(arr[lo]==x)
                return lo+1;
            return -1;
        }
        pos=lo+((x-arr[lo])*(hi-lo)/(arr[hi]-arr[lo]));
        if(arr[pos]==x)
            return pos+1;
        if(arr[pos]<x)
        {
            lo=pos+1;
        }
        else
        {
            hi=pos-1;
        }
    }
    return -1;
}
int main()
{
    int n,x,i,index;
    scanf("%d%d",&n,&x);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    index=interpoSearch(arr,x,0,n-1);
    if(index==-1)
        printf("\nNot Found");
    else
        printf("\nFound at index %d",index);
    return 0;
}
