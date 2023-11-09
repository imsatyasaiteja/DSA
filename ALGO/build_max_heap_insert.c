/* We are using max_heap_insert function in build_max_heap to construct a max heap A */

#include <stdio.h>
#define N 20

int A[N], i, k, s, key;
int B[N];
void build_max_heap(int A[N]);
void heap_increase_key(int A[N], int i, int key);
void max_heap_insert(int A[N], int key);


void main()
{
    printf(" Enter the number of values you want to insert in max heap : ");
    scanf("%d", &k);
    printf("\n");

    s = k;

    for (i = 1; i <= k; i++)
    {
        printf(" Enter the value in A[%d] : ", i);
        scanf("%d",&A[i]);
    }
    printf("\n The values in the heap are : \n");
    for (i = 1; i <= k; i++)
    {
        printf(" %d,",A[i]);
    }

    printf("\n Now we apply build max heap on this heap A ");
    build_max_heap(A);

    printf("\n The values in the heap after applying build max heap are : \n");
    for (i = 1; i <= k; i++)
    {
        printf(" %d,",A[i]);
    }
    return;
}

void heap_increase_key(int A[N], int i, int key)
{
    int temp;
    if(key < A[i])
    {
        printf("\n The key value entered is smaller than the value of index i ");
    }

    A[i] = key;

    while(i>1 && A[i/2] < A[i])
    {
        temp = A[i/2];
        A[i/2] = A[i];
        A[i] = temp;

        i = i/2;
    }
}

void max_heap_insert(int A[N], int key)
{
    s++;
    A[s] = -1569325055;
    heap_increase_key(A, s, key);
}

void build_max_heap(int A[N])
{
    for (i=2; i<=k; i++)
    {
        B[i-1] = A[i];
        s--;
    }
    for (i=1; i<k; i++)
    {   max_heap_insert(A, B[i]);
    }
}
