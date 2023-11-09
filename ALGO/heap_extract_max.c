/* The heap extract max is used to delete an element from the heap
and return that value
*/

#include<stdio.h>
#define M 20

int A[M], i, s, k, max;
void heap_extract_max(int A[M]);

void main()
{   
    printf(" Enter the maximum number of nodes you want to insert : ");
    scanf("%d",&k);
    printf("\n");

    s = k;

    for (i = 1; i <= k; i++)
    {
        printf(" Enter the number you want to insert in A[%d] : ",i);
        scanf("%d",&A[i]);
    }

    heap_extract_max(A);

    printf("\n The heap after extracting the max value is : \n");
    for (i = 1; i <= s; i++)
    {
        printf(" %d, ",A[i]);
    }

    return;
}

void max_heapify(int A[M], int i)
{
    int l = 2*i;
    int r = 2*i + 1;
    int largest, temp;

    if(l<=s && A[l] > A[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if(r<=s && A[r] > A[largest])
    {
        largest = r;
    }

    if(largest != i)
    {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        max_heapify(A, largest);
    }

}

void heap_extract_max(int A[M])
{
    if(s < 1)
    {
        printf(" Heap underflow");
    }

    max = A[1];
    A[1] = A[s];
    s = s - 1;
    max_heapify(A, 1);

    printf("max is %d",max);
    return;
}
