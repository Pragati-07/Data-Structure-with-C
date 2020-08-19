/*
    Problem 5 : int arr[]={1,2,4,2,3,5,4,7,6,5,8,6,7,6,5,4,5,4,5,4,3,2,1,2,3,4,5,6,7,8,9,0,9,8,9,0,9,8,7,8,7,6,7,6,5,3}
        Print frequency of all elements in above array lie between(0-10) in a single iteration of above loop.
        Hint:- u can use another array of size 10.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[]={1,2,4,2,3,5,4,7,6,5,8,6,7,6,5,4,5,4,5,4,3,2,1,2,3,4,5,6,7,8,9,0,9,8,9,0,9,8,7,8,7,6,7,6,5,3};
    int i,count[10];
    int n=sizeof(arr)/sizeof(int);
    for(i=0;i<10;i++)
    {
        count[i]=0;
    }
    for(i=0;i<n;i++)
    {
        count[arr[i]]+=1;
    }
    for(i=0;i<10;i++)
    {
        printf("%d ",count[i]);
    }
    return 0;
}
