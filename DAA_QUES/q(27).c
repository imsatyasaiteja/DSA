#include <stdio.h>
int f[] = {3, 6, 3, 4, 6, 1, 8, 9, 6, 9, 9, 6, 4};


int rem(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(f[i] == f[j])
            {
                for (int k = j; k < n-1; k++)
                {
                    f[k] = f[k + 1];
                }
                n--;
                j--;
            }
        }
    }

    return n;
}

void main()
{
    int n = sizeof(f)/4;

    printf("Program that removes duplicate elements in an array\n");

    int s = rem(n);

    printf("Modified array is : ");

    for (int i = 0; i < s; i++)
    {
        printf("%d, ",f[i]);
    }

    return;
}