/*
    Problem 3 : Write a program to sort an  array and search the number from user if number exist return its index
    other wise return -1
        3.1 use selection sort or search.
        3.2 use bubble sort and search.
        3.3 use insertion sort and search
        3.4  use merge sort and search
    for practice you can use different searching techniques.
*/
#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void insertionSort(int arr[],int n)
{
    int i,j,temp;
    j=1;
    while(j<n)
    {
        i=j-1;
        temp=arr[j];
        while(i>=0 && temp<arr[i])
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=temp;
        j++;
    }
}
void bubbleSort(int arr[],int n)
{
    int i,j,flag=0;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
               {
                flag=1;
                swap(&arr[j],&arr[j+1]);
               }
        }
        if(flag==0)
            break;
    }
}
void merge(int arr[],int l,int m,int h)
{
    int b[h-l+1];
    int i,j,k;
    i=l;
    j=m+1;
    k=0;
    while(i<=m && j<=h)
    {
        if(arr[i]<arr[j])
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
    k=0;
    for(i=l;i<=h;i++)
    {
        arr[i]=b[k];
        k++;
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
void selectionSort(int arr[],int n)
{
    int i,j,min;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        swap(&arr[i],&arr[min]);
    }
}
int binarySearch(int arr[],int l,int h,int x)
{
    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(arr[mid]==x)
            return mid+1;
        if(arr[mid]<x)
            return binarySearch(arr,mid+1,h,x);
        else
            return binarySearch(arr,l,mid-1,x);
    }
    return -1;
}
int main()
{
    int i,n,ch;
    printf("Enter number of elements to be stored in an array : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter elements of array : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nPress 1 to use Selection Sort.");
    printf("\nPress 2 to use Bubble Sort.");
    printf("\nPress 3 to use Insertion Sort.");
    printf("\nPress 4 to use Merge Sort.");
    printf("\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch){
    case 1: selectionSort(arr,n);
        break;
    case 2: bubbleSort(arr,n);
        break;
    case 3: insertionSort(arr,n);
        break;
    case 4: mergeSort(arr,0,n-1);
        break;
    default: printf("\nWrong Choice .");
    }
    int element,index;
    printf("\nEnter element to search : ");
    scanf("%d",&element);
    index=binarySearch(arr,0,n-1,element);
    if(index==-1)
        printf("\nElement not found");
    else
        printf("\nElement found at index %d.\n",index);
    return 0;
}
