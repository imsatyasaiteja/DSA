/* Fibonacci program using dynamic programming approach*/

#include<stdio.h>
#define M 20
int f(int n);
int T[M];

int main()
{   int n;
    printf(" Enter the value of n : ");
    scanf("%d",&n);
    printf("\n The value of f(n) is : %d",f(n));
}

int f(int n)
{  
    if (n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    if(T[n] != '\0')
    {
        return T[n];                                // The value of T[n] stored previously is being used instead of calculating it again
    }
    else
    {
        T[n] = f(n - 1) + f(n - 2);                 // Here T[n] is an array that is used to store the values of f(n) at each iteration
        return T[n];
    }
}

// The time complexity of fibonacci algorithm is successfully reduced to O(n) from exponential
// The space complexity would be O(n) because of the 1-D Array used 