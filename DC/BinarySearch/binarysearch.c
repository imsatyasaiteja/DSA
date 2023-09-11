// Binary Search

/*
This program searches for a given element in a given 
sorted array by implementing the Binary Search Algorithm
*/

#include<stdio.h>

int A[] = {3, 12, 21, 30, 42, 51, 60, 72, 81};
int x = 72;
int BinarySearch(int i, int j);

int main()
{
    int index = BinarySearch(0, 8);
    
    if(index >= 0)
    {
        printf("A[%d] = %d", index, x);
    }
    else
    {
        printf("%d Not Found", x);
    }

    return 0;
}

int BinarySearch(int i, int j)
{
    int index = -1;

    if(i == j)
    {
        if(A[i] == x)
        {
            return i;
        }
    }
    else
    {
        int mid = (i + j) / 2;

        if(A[mid] == x)
        {
            return mid;
        }
        else if(A[mid] > x)
        {
            index = BinarySearch(i, mid);
        }
        else
        {
            index = BinarySearch(mid + 1, j);
        }
    }

    return index;
}

/*
Time Complexity (TC) = O(logn)
Space Complexity (SC) = O(logn)
*/