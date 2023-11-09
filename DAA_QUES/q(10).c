#include<stdio.h>
#define N 20

int A[N], i, k;
void max_heapify(int A[N], int i);
void build_max_heap(int A[N]);

void main()
{
    printf(" Enter the number of values you want to insert in max heap : ");
    scanf("%d", &k);
    printf("\n");

    for (i = 1; i <= k; i++)
    {
        printf(" Enter the value in A[%d] : ", i);
        scanf("%d", &A[i]);
    }
    printf("\n The values in the heap are : \n");
    for (i = 1; i <= k; i++)
    {
        printf(" %d,", A[i]);
    }

    printf("\n Now we apply build max heap on this heap A ");
    build_max_heap(A);

    printf("\n The values in the heap after applying build max heap are : \n");
    for (i = 1; i <= k; i++)
    {
        printf(" %d,", A[i]);
    }
    return;
}

void max_heapify(int A[N], int i)
{
    int temp;
    int l = 2 * i;                      // The index value of left child is 2*i of a parent of index i
    int r = 2 * i + 1;                  // The index value of right child is 2*i+1 of a parent of index of i
    int largest;

    if (l <= k && A[l] > A[i])          // Here we are checking if the left child exists using l<=k
    {                                   // and when it exists we are checking if the value is greater than its parent using A[l] > A[i]
        largest = l;                    // If the left child is greater than its parent then we store
    }                                   // this index in an integer variable called "largest"
    else
    {                                   // If the left child does not exist (or) is not greater than its parent then
        largest = i;                    // The index value of parent itself is stored in the int variable "largest"
    }

    if (r <= k && A[r] > A[largest])    // Here we are checking if the right child exits using r<=k
    {                                   // and when it exits we are checking if the value is greater than the
        largest = r;                    // previously assigned "largest" index value i.e using A[r] > A[largest]
    }                                   // If the right child is greater than the A[largest], then value of "largest" is reassigned with "r"

    if (largest != i)                   // Finally we are checking if the value of int largest is not the same as the parent index
    {                                   // If the value of int largest is same as parent index no change occurs in the heap else
        temp = A[i];                    // the value of parent is exchanged with the value of A[largest]
        A[i] = A[largest];
        A[largest] = temp;
        max_heapify(A, largest);        // This largest value so obtained in this process further goes through a check to print the final max heap
    }
}

void build_max_heap(int A[N])
{
    for (i = (k/2)+1; i >= 1; i--)      // The max heapify code is applied from the half + 1 index down to index 1 and max heap is obtained 
    {                                   // Max heapify algorithm works from top to bottom in a heap
        max_heapify(A, i);              // Build max heap algo works it for all the indices by starting from the bottum up manner
    }
    return;
}


/* The problem with max heapify is that it checks from top to bottom and finally returns
the max heap. But this max heap so obtained at the last may not be correct in all cases.
Some elements above the parent element on which we applied max heapify may still remain
at wrong positions. In order to get rid of this problem, we use build max heap algorithm
which applies max heapify for all indices above the half of the heap and finally returns
us the max heap. 
*/
