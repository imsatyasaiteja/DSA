/*	NAME : M. SATYA SAI TEJA
    CLASS : CSE, 2ND YEAR
    ROLL : 20/11/EC/011
    DATE : 6 JUNE 2022
    QUESTION 5(ii), HUFFMAN CODES FOR DISTINCT CHARACTERS IN A TEXT FILE
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 30
#define N 128

int F[M];
char S[M][N];
char X[N];
int i, j, n;

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
    char S[M][N];
    char fname[N];
    FILE *file = NULL;
    int e = 0;
    int tot = 0;

    printf("\n\n Read the file and store the lines into an array : \n");
    printf("------------------------------------------------------\n");
    printf(" Input the filename to be opened : ");
    scanf("%s", fname);

    file = fopen(fname, "r");

    while (fgets(S[e], N, file))
    {
        S[e][strlen(S[e]) - 1] = '\0';
        e++;
    }

    tot = e;

    if (file == NULL)
    {
        printf(" Error!");
        exit(1);
    }

    printf("\n The content in '%s'file is :\n\n", fname);
    for (i = 0; i < tot; ++i)
    {
        printf(" %s\n", S[i]);
    }

    for (i = 0; i < tot; i++)
    {
        strcat(X, S[i]);
    }

    int g = strlen(X);

    // This loop removes the characters that occur more than once and stores their frequency in F[]
    for (i = 0; i < g; i++)
    {
        if (X[i] != ' ')
        {
            F[i] = 1;
            for (j = i + 1; j < g; j++)
            {
                if (X[i] == X[j] && X[i] != ' ' && X[i] != '\0')
                {
                    F[i]++;
                    X[j] = ' ';
                }
            }
        }
    }

    // This loop removes all the spaces and symbols in the sentence and brings all distinct characters together
    for (i = 0; i < g; i++)
    {
        while (X[i] == ' ' || X[i] == '.' || X[i] == ',')
        {
            for (j = i; j < g; j++)
            {
                X[j] = X[j + 1];
                F[j] = F[j + 1];
            }
        }
    }

    g = strlen(X);

    printf("\n Our final array that we convert to huffman code is : %s", X);
    printf("\n Now the frequency of each character is : ");

    for (i = 0; i < g; i++)
    {
        printf("\n %c is (%d) ", X[i], F[i]);
    }

    printf("\n\n Huffman codes : \n");
    huffTreeForm(X, F, g);

    return 0;
}