// Quick Sort

/*
This program sorts an array of elements
by implementing Quick Sort Algorithm
*/

#include<stdio.h>

int A[] = {23, 4, 16, 339, 2, 56, 425, 76, 93};

void QuickSort(int p, int q);
int Partition(int p, int q);
void Swap(int i, int j);

int main()
{
    int N = sizeof(A) / sizeof(A[0]);

    QuickSort(0, N);

    printf("Sorted A[] = {");
    for (int a = 1; a <= N; a++)
    {
        if (a == N)
        {
            printf("%d}", A[a]);
            return 0;
        }
        printf("%d, ", A[a]);
    }
}

void QuickSort(int p, int q)
{
    if(p < q)
    {
        int j = Partition(p, q+1);
        QuickSort(p, j - 1);
        QuickSort(j + 1, q);
    }
}

int Partition(int p, int q)
{
    int v = A[p];
    int i = p+1;
    int j = q-1;

    while (i < j)
    {
        while (A[i] < v && i < q)
        {
            i++;
        }

        while (A[j] > v && j > p)
        {
            j--;
        }

        if(i <= j)
        {
            Swap(i, j);
        }
    }

    A[p] = A[j];
    A[j] = v;

    return j;
}

void Swap(int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

/*
Best Case Time Complexity (TC) = n*logn
Best Case Space Complexity (SC) = logn
*/