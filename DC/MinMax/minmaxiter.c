// Min Max Iterative Approach

/*
This program finds the Minimum and Maximum elements 
in a given array using an Iterative Approach
*/

#include <stdio.h>

int A[] = {3, 30, 60, 12, 21, 81, 51, 42, 72};
void MinMax(int *max, int *min);

int main()
{
    int min, max = min = A[0];

    MinMax(&max, &min);
    printf("Max : %d, Min : %d", max, min);

    return 0;
}

void MinMax(int *max, int *min)
{
    int N = sizeof(A) / sizeof(A[0]);

    for (int i = 0; i < N; i++)
    {
        if (A[i] > *max)
        {
            *max = A[i];
        }
        else
        {
            if (A[i] < *min)
            {
                *min = A[i];
            }
        }
    }

    return;
}

/*
Time Complexity (TC) = O(n)
Space Complexity (SC) = O(1)
*/