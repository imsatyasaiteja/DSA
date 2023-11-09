#include<stdio.h>
#define M 20

int A[M], m, s, i, j;
int a, b, n;

void max_heapify(int A[M], int w);
void build_max_heap(int A[M]);
void heap_sort(int A[M]);
void find(int A[M]);
void binary_search(int A[M], int low, int high, int w);

void max_heapify(int A[M], int w)
{
    int temp, largest;
    int l = 2*w;
    int r = 2*w + 1;

    if(l<=s && A[l] > A[w])
    {
        largest = l;
    }
    else
    {
        largest = w;
    }

    if (r<=s && A[r] > A[largest] )
    {
        largest = r;
    }

    if(largest != w)
    {
        temp = A[w];
        A[w] = A[largest];
        A[largest] = temp;
        max_heapify(A, largest);
    }
    return;
}

void build_max_heap(int A[M])
{
    for(i = (m/2)+1; i >= 1; i--)
    {
        max_heapify(A, i);
    }
    return;
}

void heap_sort(int A[M])
{
    int temp;
    for (i = m; i >= 2; i--)
    {
        temp = A[i];
        A[i] = A[1];
        A[1] = temp;

        s = s - 1;
        max_heapify(A, 1);
    }
    return;
}

void main()
{
    printf("\n Enter the number of elements you want to enter in the array A : ");
    scanf("%d", &m);

    s = m;

    for (i = 1; i <= m; i++)
    {
        printf("\n Enter the value you want to store in A[%d] : ", i);
        scanf("%d", &A[i]);
    }

    build_max_heap(A);
    heap_sort(A);

    for (i = 1; i <= m; i++)
    {
        printf(" %d,",A[i]);
    }

    printf("\n");
    find(A);

    return;
}

void binary_search(int A[M], int low, int high, int w)
{
    int mid = (low + high) / 2;

    if (low <= high)
    {
        
        if (A[mid] == w)
        {
            printf("\n Pair exists (%d,%d)",a,w);
            return;
        }  
        else if (A[mid] < w)
        {
            binary_search(A, mid + 1, high, w);
        }
        else if(A[mid] > w)
        {
            binary_search(A, low, mid - 1, w);
        }
        else
        {
            printf("\n Pair does not exist");
            return;
        }
    }
    
}

void find(int A[M])
{
    char input;
    printf(" Enter an integer n : ");
    scanf("%d",&n);

    for (i = 1; i <= m; i++)
    {
        a = A[i];
        if(a<n)
        {
            b = n - a;
            binary_search(A, 1, m, b);
        }
        else
        {
            printf(" Pair does not exist\n");
        }
    }

        while(1)
        {   printf("\n Enter 'c' to continue and 'e' to exit : ");
            scanf("%c",&input);

            if(input == 'c')
            { find(A);
            }
            else if(input == 'e')
            { return;
            }
            else
            { printf(" Please enter a valid input");
            }
        }
}