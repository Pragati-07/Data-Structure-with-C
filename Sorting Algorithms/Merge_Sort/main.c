/*
        Merge Sort

    Input : 1st line - number of elements in array
            2nd line - space separated elements to be stored in array

    Output : sorted  array

    Time Complexity : O(n*logn)

*/
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int l,int m,int h)
{
    int b[h+1],i,j,k;
    i=l;
    j=m+1;
    k=l;
    while(i<=m && j<=h)
    {
        if(arr[i]<=arr[j])
        {
            b[k]=arr[i];
            i++;
        }
        else{
            b[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=m)
    {
        b[k]=arr[i];
        i++;
        k++;
    }
    while(j<=h)
    {
        b[k]=arr[j];
        j++;
        k++;
    }
    for(k=l;k<=h;k++)
    {
        arr[k]=b[k];
    }
}

void mergeSort(int arr[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(h+l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
int main()
{
     int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    mergeSort(arr,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
