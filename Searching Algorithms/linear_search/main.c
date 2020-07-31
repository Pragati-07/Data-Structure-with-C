/*
    Linear Search

Input :  First Line : n-number of elements in array and x-element to be searched
         Second Line : n space separated values of array
Output : print "Not Found" if element not present in array or print index where element is present.

Time Complexity : O(n^2)
Space Complexity : O(1)
*/
#include <stdio.h>
#include <stdlib.h>

int linearSearch(int n,int arr[],int x)
{
    int i;
    for(i=0;i<n;i++)
        if(arr[i]==x)
            return i+1;
    return -1;
}
int main()
{
    int n,i,x,index;
    scanf("%d%d",&n,&x);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    index=linearSearch(n,arr,x);
    if(index==-1)
        printf("\nNot Found");
    else
        printf("\nFound at index %d",index);
    return 0;
}
