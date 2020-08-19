/*
        Quick Sort

    Input : 1st line - number of elements in array
            2nd line - space separated elements to be stored in array

    Output : sorted  array

    Time Complexity : average case = O(n*logn), worst case = O(n^2)
*/
#include <stdio.h>
#include <stdlib.h>

int Partition(int a[],int lb,int ub)
{
 int start,end,pivot,temp;
 pivot=a[lb];
 start=lb;
 end=ub;
 while(start<end)
 {
     while(a[start]<=pivot)
     {
         start++;
     }
     while(a[end]>pivot)
     {
         end--;
     }
     if(start<end)
     {
         temp=a[start];
         a[start]=a[end];
         a[end]=temp;
     }
 }
 temp=a[lb];
 a[lb]=a[end];
 a[end]=temp;

 return end;

}

void quickSort(int arr[],int lb,int ub)
{
    int loc;
    if(lb<ub)
    {
        loc=Partition(arr,lb,ub);
        quickSort(arr,lb,loc-1);
        quickSort(arr,loc+1,ub);
    }
}

int main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quickSort(arr,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
