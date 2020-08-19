/*
Question 4. {1,2,3,4,5,6,7,8,9} swap the elements of the array means swap first from last ,
           second from second last,& so on without using any extra memory
Time Complexity : O(n)
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,j;
    int arr[]={1,2,3,4,5,6,7,8,9};
    n=sizeof(arr)/4;
    j=n-1;
    for(i=0;i<=n/2;i++)
    {
        arr[i]=arr[i]*10+arr[j];
        arr[j]=arr[i]/10;
        arr[i]=arr[i]%10;
        j--;
    }
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
