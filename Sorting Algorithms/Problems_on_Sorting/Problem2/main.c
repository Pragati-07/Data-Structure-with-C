/*
    Problem 2 : Write a program to get name as user input and print it in following  pyramid pattern
            input:- KARTIK
            output:-
                    K
                    KA
                    KAR
                    KART
                    KARTI
                    KARTIK
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,i,j;
    char name[15];
    scanf("%s",name);
    n=strlen(name);
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("%c",name[j]);
        }
        printf("\n");
    }
    return 0;
}
