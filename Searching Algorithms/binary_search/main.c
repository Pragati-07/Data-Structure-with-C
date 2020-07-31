/*
    Binary Search

Input :  First Line : contains n-number of elements in array and x-element to be searched separated by space
         Second Line : n space separated values of array
Output : return -1 if element not present in array or return index where element is present.

Time Complexity : O(log(n))
Space Complexity : O(log(n))
*/
#include <stdio.h>
#include <stdlib.h>
int binarySearch(int arr[],int x,int l,int h)
{
    int mid;
    if(h<l)
        return -1;
    mid=(l+h)/2;
    if(arr[mid]==x)
        return mid+1;
    if(arr[mid]>x)
        return binarySearch(arr,x,0,mid);
    else
        return binarySearch(arr,x,mid+1,h);

}
int main()
{
    int n,i,x,index;
    scanf("%d%d",&n,&x);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    index=binarySearch(arr,x,0,n-1);
    if(index==-1)
        printf("\nNot Found");
    else
        printf("\nFound at index %d",index);
    return 0;
}
