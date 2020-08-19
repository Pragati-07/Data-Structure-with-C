/*
        Selection Sort

    Input : 1st line - number of elements in array
            2nd line - space separated elements to be stored in array

    Output : sorted  array

    Time Complexity : O(n^2)

*/
#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[],int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    selectionSort(arr,n);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
