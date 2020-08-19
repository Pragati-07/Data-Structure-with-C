/*
    Problem 1 : Create an array by user of size 2n and shuffle array with nth element
                e.g. Input: nums=[2,5,1,3,4,7], n=3
                     Output: [2,3,5,4,1,7]
    Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,temp,j;
    printf("Enter position from where to shuffle array : ");
    scanf("%d",&n);
    int i,nums[2*n];
    printf("\nEnter elements in array of size %d : ",2*n);
    for(i=0;i<2*n;i++)
    {
        scanf("%d",&nums[i]);
    }
    i=0;
    k=n;
    while(i<=2*n-2)
    {
        if(i%2!=0)
        {
            temp=nums[k];
            j=k;
            while(j>i)
            {
               nums[j]=nums[j-1];
               j--;
            }
            nums[i]=temp;
            k++;
        }
        i++;
    }
    for(i=0;i<2*n;i++)
        printf("%d ",nums[i]);
    return 0;
}
