#include<stdio.h>
#include<stdlib.h>
#define N 10
int f[N];

void main()
{
    int n;
    printf("Program to reverse elements of an array \n");
    printf("Enter the number of elements(n) : ");
    scanf("%d",&n);
    printf("Enter the integers in array f[N] \n");
    
    for (int i = 0; i < n; i++)
    {
        printf("f[%d] : ",i);
        scanf("%d",&f[i]);
    }

    int *ptr, k[n];

    for (int i = n; i > 0; i--)
    {
        ptr = &f[i-1];
        k[n-i] = *ptr;
    }

    printf("Therefore the reversed array of f[N] is : \n");
    for (int i = 0; i < n; i++)
    {
        f[i] = k[i];
        printf("%d, ",f[i]);
    }

    return;
}