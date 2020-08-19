/*
    Problem 2 : Here size of an array is 3 arr[3]={1,2,3} create a function if user insert next element it
                returns with a message "Array Complete" instead of any error message
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,elem;
    printf("Enter number of elements to be stored : ");
    scanf("%d",&n);
    int arr[n];
    int i=0;
    printf("\nEnter elements : ");
    while(1)
    {
        printf("\nElement %d : ",i+1);
        scanf("%d",&elem);
        if(i==n)
        {
            printf("\nArray Complete");
            break;
        }
        arr[i]=elem;
        printf("Element inserted.");
        i++;
    }
    return 0;
}
