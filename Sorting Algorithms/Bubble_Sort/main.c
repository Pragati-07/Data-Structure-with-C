/*
        Bubble Sort

    Input : 1st line - number of elements in array
            2nd line - space separated elements to be stored in array

    Output : sorted  array

    Time Complexity : O(n^2)

*/
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[],int n)
{
    int i,j,flag,temp;
    for(i=0;i<n-1;i++)
    {
        flag=1;
     for(j=0;j<n;j++)
     {
         if(arr[j]>arr[j+1])
         {
             flag=0;
             temp=arr[j];
             arr[j]=arr[j+1];
             arr[j+1]=temp;
         }
     }
     if(flag==1)
        break;
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    bubbleSort(arr,n);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
