#include<stdio.h>
#define N 20

int A[N], i, k, s;
void heap_sort(int A[N]);
void max_heapify(int A[N], int i);
void build_max_heap(int A[N]);

void main()
{
    printf(" Enter the number of elements you want to insert in the heap : ");
    scanf("%d",&k);

    s = k;

    for (i = 1; i <= k; i++)
    {  printf("\n Enter the value you want into A[%d] : ", i);
       scanf("%d",&A[i]);
    }

    printf("\n The values stored in the heap A are : ");

    for (i = 1; i <= k; i++)
    {
        printf(" %d,", A[i]);
    }

    printf("\n Now we apply build max heap on this heap A ");
    build_max_heap(A);

    printf("\n\n The max heap of A is as follows : ");
    for (i = 1; i <= k; i++)
    {
        printf(" %d,", A[i]);
    }

    printf("\n Now we apply heapsort on this heap A ");
    heap_sort(A);

    printf("\n\n The sorted heap A is as follows : ");
    for (i = 1; i <= k; i++)
    {
        printf(" %d,", A[i]);
    }

    return;
}

void max_heapify(int A[N], int i)
{
    int temp;
    int l = 2*i;
    int r = 2*i+1;
    int largest;

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

    return;
}

void build_max_heap(int A[N])
{
    for (i = (k/2)+1; i >= 1; i--)
    {
        max_heapify(A, i);
    }
    return;
}

void heap_sort(int A[N])
{
    int temp;                       // This sorting of array A is done by using build_max_heap and max_heapify              
                                    // First the given heap is made into a max heap
    for (i = k; i >= 2; i--)         
    {
        temp = A[i];               // The maximum value of a max heap is A[1], this is swapped with the A[i] at each iteration
        A[i] = A[1];               
        A[1] = temp;

        s = s - 1;                 // The value of s is decreased at each iteration because we don't need the largest element,
        max_heapify(A, 1);         // which is sorted and placed at the correct place. The max heapify works for s = s-1 at each iteration.
    }

    return;
}


/* This heap sort program written above sorts the given set of elements in ascending order. The 
user need not enter a max heap for sorting, this program converts the given set of elements to 
max heap first and then it starts sorting.
*/

// example : 9 6 5 0 8 2 1 3