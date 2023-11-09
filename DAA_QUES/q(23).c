#include<stdio.h>
#define N 20
int f[N];

int fib(int n)
{
    f[0] = 0;
    f[1] = 1;

    if(n != 0 && n != 1)
    {   
        f[n] = fib(n - 1) + fib(n - 2);
    }

    return f[n];
}

void main()
{
    int n;
    printf("Program to find nth element of the fibonacci series \n");
    printf("Enter the value of n : ");
    scanf("%d", &n);

    fib(n);

    printf("The fibonacci series is : ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ",f[i]);
    }
    
    printf("\nThe %dth element is : %d",n,fib(n));

    return;
}

