/*
        Insertion Sort

    Input : 1st line - number of elements in array
            2nd line - space separated elements to be stored in array

    Output : sorted  array

    Time Complexity : O(n^2)

*/
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[],int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    insertionSort(arr,n);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
