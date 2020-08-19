/*
    Problem 4 : int arr[]={2,4,3,1,7,6,9,8,5,13,11,19,17,16,18,13}
            Compare steps to sort the following array using selection vs bubble vs insertion vs merge
            print number of steps of all.
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
int bubbleSort(int arr[],int n)
{
    int i,j,c,f=0;
    c=0;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                f=1;
                c++;
            }
        }
    if(f==0)
        break;
    }
    return c;
}
int main()
{
    int i,ch;
    int arr[]={2,4,3,1,7,6,9,8,5,13,11,19,17,16,18,13};
    int n=sizeof(arr)/sizeof(int);
    int steps;
    printf("\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n4.Merge Sort\nEnter your choice : ");
    scanf("%d",&ch);
    steps=bubbleSort(arr,n);
    printf("%d\n",steps);
    //for(i=0;i<n;i++)
    //    printf("%d ",arr[i]);
    return 0;
}
