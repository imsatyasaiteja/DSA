/*	NAME : M. SATYA SAI TEJA
    CLASS : CSE, 2ND YEAR
    ROLL : 20/11/EC/011
    DATE : 4 JUNE 2022
    QUESTION 4, HUFFMAN CODES FOR DISTINCT CHARACTERS IN A GIVEN STRING
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 30

int F[M];
char S[M];
int i, j;

// NODE STRUCT :
struct node
{
    char hc;
    unsigned f;
    struct node *left, *right;
};

// MIN HEAP STRUCT :
struct minHeap
{
    unsigned size;
    unsigned capacity;
    struct node **H;
};

// NEW NODE :
struct node *newNode(char hc, unsigned f)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->left = temp->right = NULL;
    temp->hc = hc;
    temp->f = f;

    return temp;
}

// SWAP NODES :
void swap(struct node **a, struct node **b)
{
    struct node *temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// MIN HEAPIFY :
void minHeapify(struct minHeap *m, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    if (l < m->size && m->H[l]->f < m->H[smallest]->f)
    {
        smallest = l;
    }

    if (r < m->size && m->H[r]->f < m->H[smallest]->f)
    {
        smallest = r;
    }

    if (smallest != i)
    {
        swap(&m->H[smallest], &m->H[i]);
        minHeapify(m, smallest);
    }
}

// EXTRACT MIN :
struct node *extractMin(struct minHeap *m)
{
    struct node *temp = m->H[0];

    m->H[0] = m->H[m->size - 1];

    --m->size;

    minHeapify(m, 0);

    return temp;
}

// INSERT MIN HEAP :
void insertMinHeap(struct minHeap *m, struct node *n)
{
    ++m->size;
    int i = m->size - 1;

    while (i && n->f < m->H[(i - 1) / 2]->f)
    {
        m->H[i] = m->H[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    m->H[i] = n;
}

// CREATE MIN HEAP :
struct minHeap *createMinHeap(char data[], int freq[], int size)
{
    struct minHeap *m = (struct minHeap *)malloc(sizeof(struct minHeap));
    m->size = 0;
    m->capacity = size;
    m->H = (struct node **)malloc(m->capacity * sizeof(struct node *));

    for (int i = 0; i < size; ++i)
    {
        m->H[i] = newNode(data[i], freq[i]);
    }

    m->size = size;

    int s = m->size - 1;
    int i;

    for (i = (s - 1) / 2; i >= 0; --i)
    {
        minHeapify(m, i);
    }

    return m;
}

// BUILD HUFFMAN TREE :
struct node *buildHuffTree(char data[], int freq[], int size)
{
    struct node *left, *right, *top;

    struct minHeap *m = createMinHeap(data, freq, size);

    while (m->size != 1)
    {
        left = extractMin(m);
        right = extractMin(m);
        top = newNode('$', left->f + right->f);

        top->left = left;
        top->right = right;

        insertMinHeap(m, top);
    }

    return extractMin(m);
}

// HUFFMAN CODE :
void huffCode(struct node *root, int A[], int top)
{
    if (root->left)
    {
        A[top] = 0;
        huffCode(root->left, A, top + 1);
    }

    if (root->right)
    {
        A[top] = 1;
        huffCode(root->right, A, top + 1);
    }

    if (!(root->left) && !(root->right))
    {
        printf(" %c : ", root->hc);

        for (i = 0; i < top; ++i)
        {
            printf("%d", A[i]);
        }
        printf("\n");
    }
}

// HUFFMAN TREE FORMATION :
void huffTreeForm(char data[], int freq[], int size)
{
    struct node *root = buildHuffTree(data, freq, size);
    int A[M], top = 0;

    huffCode(root, A, top);
}

// DRIVER CODE :
int main()
{

    printf(" Enter a string of characters to obtain huffman codes for all distinct characters : ");
    scanf("%[^\n]", S);

    int N = strlen(S);

    for (i = 0; i < N; i++)
    {
        if (S[i] != ' ')
        {
            F[i] = 1;
            for (j = i + 1; j < N; j++)
            {
                if (S[i] == S[j] && S[i] != ' ' && S[i] != '\0')
                {
                    F[i]++;
                    S[j] = ' ';
                }
            }
        }
    }


    for (i = 0; i < N; i++)
    {
        while (S[i] == ' ')
        {
            for (j = i; j < N; j++)
            {
                S[j] = S[j + 1];
                F[j] = F[j + 1];
            }
        }
    }

    N = strlen(S);

    printf("\n Array that we should convert to huffman code is : %s \n", S);

    for (i = 0; i < N; i++)
    {
        printf("\n Frequency of %c is %d ", S[i], F[i]);
    }

    printf("\n\n Huffman codes : \n");
    huffTreeForm(S, F, N);

    return 0;
}