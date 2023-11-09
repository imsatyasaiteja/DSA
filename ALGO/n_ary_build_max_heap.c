#include<stdio.h>
#define M 20

int n, s, A[M];                                                                // Here n is the number of children, s is the heapsize
int i, k;
void n_ary_max_heapify(int A[M],int i);
void n_ary_build_max_heap(int A[M]);

void main()
{
    printf(" Enter the value of n for the n-ary heap you want to construct : ");
    scanf("%d",&n);

    printf("\n Enter the number of nodes you want to insert : ");
    scanf("%d", &s);

    for (i=1; i <= s;i++)
    {
        printf("\n Enter the value you want to store in A[%d] : ", i);
        scanf("%d",&A[i]);
    }

    printf("\n The heap is : \n");

    for (i = 1; i <= s; i++)
    {
        printf(" %d,",A[i]);
    }

    n_ary_build_max_heap(A);

    printf("\n The heap after applying build max heap is : \n");

    for (i = 1; i <= s; i++)
    {
        printf(" %d,", A[i]);
    }
}

void n_ary_max_heapify(int A[M], int i)
{                                             
    int largest = i;
    int temp;

    for (k = 1; k <= n;k++)
    {
        int c = n*(i-1) + (k+1);                                         // Here c is the kth child of a parent "i"
        if(c<=s && A[c] > A[largest])
        {
            largest = c;
        }
    }

    if(largest != i)
    {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        n_ary_max_heapify(A, largest);
    }
}

void n_ary_build_max_heap(int A[M])
{
    for (i = (s/2)+1; i>= 1; i--) 
    {                                  
        n_ary_max_heapify(A, i);             
    }
    return;
}