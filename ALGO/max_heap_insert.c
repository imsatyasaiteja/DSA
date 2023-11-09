/* In this program max_heapify and build_max programs were written so that
the program functions correctly even if the user does not enter a max heap */

#include<stdio.h>
#define N 20

int A[N], i, k, s, key;
void max_heapify(int A[N], int i);
void build_max_heap(int A[N]);
void heap_increase_key(int A[N], int s, int key);
void max_heap_insert(int A[N], int key);

void main()
{
    printf(" Enter the number of values you want to insert in max heap : ");
    scanf("%d",&k);
    printf("\n");

    s = k;

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

    printf("\n\n Now we apply build max heap on this heap A ");
    build_max_heap(A);

    printf("\n The values in the heap after applying build max heap are : \n");
    for (i = 1; i <= k; i++)
    {
        printf(" %d,", A[i]);
    }

    printf("\n\n Enter the value you key value you want to enter : ");
    scanf("%d",&key);

    max_heap_insert(A, key);

    printf(" The values in the heap after inserting a key %d : \n",key);
    for (i = 1; i<=s; i++)
    {
        printf(" %d,", A[i]);
    }

    return;
}

void max_heapify(int A[N], int i)
{
    int temp;
    int l = 2*i;
    int r = 2*i + 1;
    int largest;

    if (l <= s && A[l] > A[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if (r <= s && A[r] > A[largest])
    {
        largest = r;
    }

    if (largest != i)
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
    for (i = (k / 2) + 1; i >= 1; i--)
    {
        max_heapify(A, i);
    }
    return;
}

void heap_increase_key(int A[N], int s, int key)
{
    int temp;
    if(key < A[s])                                                          // Here we are checking if the key we want to insert is less than A[i]
    {
        printf("New key is smaller than current key");
        return;
    }
    A[s] = key;                                                            // If key is not less than A[i] then it is assigned the value of key

    while(s>1 && A[(s/2)]<A[s])                                            // Now we are running this loop if parent is less than child
    {
        temp = A[s];
        A[s] = A[s/2];                                                     // Here we are swapping the values of child and
        A[s/2] = temp;                                                     // parent when child is greater than parent

        s = s/2;                                                           // The index of child is now updated to its parent
    }
}

void max_heap_insert(int A[N], int key)
{
    s = s+1;                                                               // The value of heap size is incremented
    A[s] = -1569325055;                                                    // This newly inserted key is assigned a -infinity value
    heap_increase_key(A,s,key);                                            // Now, the heap increase key is called
}




/* (6.5.2) The operation of MAX-HEAP-INSERT(A, 10) on the heap A = { 15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1 } is ?
The answer is A = { 15, 13, 10, 5, 12, 9, 7, 4, 0 , 6, 2, 1, 8 }
*/
