// CODE FOR MERGE SORTING :

#include<stdio.h>
#define N 20

int A[N], q, i, j, k;
void merge_sort(int A[N], int p, int r);
void merge(int A[N], int p, int q, int r);

// DRIVER CODE :
void main()
{
    int p = 1;
    int r;
    printf("\n Enter the number of elements you want to insert in array A : ");
    scanf("%d",&r);

    printf("\n");

    // User input array A[] :
    for(i=0; i<r; i++)
    {   printf(" Enter the value in A[%d] : ", i);
        scanf("%d",&A[i]);
    }

    // Printing array A[] elements :
    printf("\n The elements in the array A are :  \n");
    for (i=0; i<r; i++)
    {
        printf(" %d,",A[i]);
    }

    // Merge sort :
    printf("\n\n Now let us implement merge sort on this array A ");
    merge_sort(A, p, r);

    // The final array after sorting :
    printf("\n The elements in the array A are :  \n");
    for (i=0; i<r; i++)
    {
        printf(" %d,", A[i]);
    }

    return;
}

// MERGE SORT :
void merge_sort(int A[N], int p, int r)
{
    if(p<r)                                                                    // p is the left index, q is the mid index, r is the right index    
    {
        q = (p + r) / 2;                                                       // The mid index q is being calculated
        merge_sort(A, p, q);                                                   // merge sort is being applied on the left (p to q) sub array
        merge_sort(A, q + 1, r);                                               // merge sort is being applied on the right (q+1 to r) sub array
        merge(A, p, q, r);                                                     // merging of both the left and right sub arrays take place, elements in a sorted 
        return;
    }
}

// MERGE FUNCTION :
void merge(int A[N], int p, int q, int r)
{
    int n1 = (q - p) + 1;                                                       // The size of left sub array is n1. It's length is (q-p)+1, 
    int n2 = (r - q);                                                           // The size of right sub array is n2. It's length is r-q
   
    int L[N], R[N];                                                                                                                            

    for (i=0; i<n1;i++)                                                        
    {
        L[i] = A[p + i - 1];                                                    // The array L is being assigned the corresponding element of the left sub array of A
    }

    for (j=0; j<n2; j++)                                                        
    {
        R[j] = A[q + j];                                                        // The array R is being assigned the corresponding element of the right sub array of A
    }

    i = 0;
    j = 0;

    for (k=p; k<=r; k++)                                                    
    {   
        if(L[i] <= R[j])                                                        // Comparing left and right sub array elements
        {
            A[k] = L[i];                                                        // If left is smaller than right, it is stored in A[k]
            i++;
        }
        else
        {
            A[k] = R[j];                                                        // else right is stored in A[k]
            j++;
        }
    }
    return;
}