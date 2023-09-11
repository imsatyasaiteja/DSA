// Min Max Divide & Conquer Strategy

/*
This program finds the Minimum and Maximum elements 
in a given array using Divide & Conquer Strategy
*/

#include<stdio.h>

int A[] = {3, 30, 60, 12, 21, 81, 51, 42, 72};
void MinMax(int i, int j, int *max, int *min);

int main()
{
    int min, max = min = A[0];

    MinMax(0, 8, &max, &min);
    printf("Max : %d, Min : %d", max, min);

    return 0;
}

void MinMax(int i, int j, int *max, int *min)
{
    int min1, max1 = min1 = A[0];

    if (i == j)
    {
        *max = *min = A[i];
    }
    else if (j == i + 1)
    {
        if (A[i] < A[j])
        {
            *max = A[j];
            *min = A[i];
        }
        else
        {
            *max = A[i];
            *min = A[j];
        }
    }
    else
    {
        int mid = (i + j) / 2;

        MinMax(i, mid, max, min);
        MinMax(mid + 1, j, &max1, &min1);

        if (max1 > *max)
        {
            *max = max1;
        }
        if (min1 < *min)
        {
            *min = min1;
        }
    }

    return;
}

/*
Time Complexity (TC) = O(n)
Space Complexity (SC) = O(logn)
*/