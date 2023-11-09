#include<stdio.h>
#include<stdlib.h>
#define N 20

int main()
{
    int s;
    printf("Enter the number of values you want to store in the stack: ");
    scanf("%d",&s);

    char A[N];

    for (int i = 0; i < s; i++)
    {
        printf("\nA[%d] : ",i);
        scanf("%c",&A[i]);
    }

    for (int i = 0; i < s; i++)
    {
        printf("\nA[%d] : %c",i,A[i]);
    }
}