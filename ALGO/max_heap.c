#include<stdio.h>
#define N 20

int A[N], i, k;
void max_heapify(int A[N], int i);

void main()
{
    printf(" Enter the number of values you want to insert in max heap : ");
    scanf("%d", &k);
    printf("\n");

    for (i = 1; i <= k;i++)
    {
        printf(" Enter the value in A[%d] : ", i);
        scanf("%d",&A[i]);
    }
    printf("\n The values in the heap are : \n");
    for (i = 1; i <= k; i++)
    {
        printf(" %d,",A[i]);
    }

    printf("\n\n Enter the index of an element on which you want to apply max heapify : ");
    scanf("%d",&i);

    max_heapify(A, i);

    printf("\n The values in the heap after max heapify are : \n");
    for (i = 1; i <= k; i++)
    {
        printf(" %d,", A[i]);
    }
    return;
}

void max_heapify(int A[N], int i)
{
    int temp;
    int l = 2*i;                    // The index value of left child is 2*i of a parent of index i
    int r = 2*i + 1;                // The index value of right child is 2*i+1 of a parent of index of i
    int largest;

    if(l<=k && A[l] > A[i])         // Here we are checking if the left child exists using l<=k 
    {                               // and when it exists we are checking if the value is greater than its parent using A[l] > A[i]
        largest = l;                // If the left child is greater than its parent then we store
    }                               // this index in an integer variable called "largest"
    else
    {                               // If the left child does not exist (or) is not greater than its parent then
        largest = i;                // The index value of parent itself is stored in the int variable "largest"
    }

    if(r<=k && A[r] > A[largest])   // Here we are checking if the right child exits using r<=k
    {                               // and when it exits we are checking if the value is greater than the 
        largest = r;                // previously assigned "largest" index value i.e using A[r] > A[largest]
    }                               // If the right child is greater than the A[largest], then value of "largest" is reassigned with "r" 
    
    if(largest != i)                // Finally we are checking if the value of int largest is not the same as the parent index
    {                               // If the value of int largest is same as parent index no change occurs in the heap else
        temp = A[i];                // the value of parent is exchanged with the value of A[largest] 
        A[i] = A[largest];          
        A[largest] = temp;      
        max_heapify(A, largest);    // This largest value so obtained in this process further goes through a check to print the final max heap
    }
}



// The time complexity of this max heapify function is O(logn). The initial steps take O(1), but the recursive step takes O(logn)
// Space complexity of max heapify function is O(logn). 