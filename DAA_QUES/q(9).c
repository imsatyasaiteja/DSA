/*	NAME : M. SATYA SAI TEJA
    CLASS : CSE, 2ND YEAR
    ROLL : 20/11/EC/011
    DATE : 8 JUNE 2022
    QUESTION 6(ii), FIND MST USING PRIMS ALGORITHM USING ADJACENCY MATRIX REPRESENTATION OF A GRAPH
*/

#include<stdio.h>
#define M 10
#define I 9999999

int x, y, w, A[M][M];
int N, E;
void display();
void prims(int s);

// CREATE ADJ MATRIX OF GRAPH :
int create()
{
    int z = 1;
    for (x = 1; x <= N; x++)
    {    for (y = 1; y <= N; y++)
        {
            A[x][y] = 0;                                                                        
        }

    }

    printf("\n Enter the node values between which you want an edge and their weigths: ");

    while (z <= E)
    {
        printf("\n");
        printf("\t x = ");
        scanf("%d",&x);
        printf("\t y = ");
        scanf("%d",&y);
        printf("\t w = ");
        scanf("%d",&w);

        if (x == y)
        {
            printf("\n Same Vertex!, self loop is not possible in a simple undirected graph \n");
        }
        else if(x>N || y>N)
        {
            printf("\n Vertex x or y is greater the number of nodes");
        }
        else
        {
            A[x][y] = w;                                                                        
            A[y][x] = w;
            z++;
        }
    }

    display(A);                                                                                 
    return A[M][M];
}

// DISPLAY ADJ MATRIX :
void display()
{
    printf("\n The Adj matrix representation of graph is as follows : \n\n");
    for (int x = 1; x <= N; x++)
    {
        for (int y = 1; y <= N; y++)
        {
            printf(" %d ", A[x][y]);
        }
        printf("\n");
    }
    return;
}

// MAIN FUNCTION :
int main()
{
    int s;
    printf("\n Enter the number of Nodes (N) you want to insert : ");
    scanf("%d",&N);
    printf("\n Enter the number of Edges (E) you want to insert : ");
    scanf("%d",&E);

    create(A);
    printf("\n Enter the index from which you want to find the minimum spanning tree : ");
    scanf("%d",&s);

    printf("\n");
    prims(s);

    return 0;
}
 
// MST USING PRIMS :
void prims(int s)
{
    int V[N];                                                                  
    int e = 1;                                                                 
    int a, b, min;                                                             
    int sum = 0;                                                               

    for (x = 1; x <= N; x++)
    {
        V[x] = 0;                                                              
    }

    V[s] = 1;                                                                  

    while (e < N)                                                              
    {
        min = I;                                                              
        a = b = 0;                                                             

        for (x = 1; x <= N; x++)                                               
        {
            if (V[x] == 1)                                                     
            {
                for (y = 1; y <= N; y++)                                       
                {
                    if (V[y] == 0 && A[x][y] != 0)                              
                    { 
                        if (min > A[x][y])                                     
                        {   min = A[x][y];                                     
                            a = x;
                            b = y;                                             
                        }
                    }
                }
            }
        }

        printf(" Edge : (%d) <--> (%d), weight : %d \n",a,b, A[a][b]);
        V[b] = 1;                                                              
        sum += A[a][b];                                                       
        e++;                                                                    
    }

    printf("\n The minimum sum of the MST so formed is : %d",sum);             
    return;
}

// example : 1 2 7 2 5 9 1 3 3 3 5 7 1 4 12 4 5 5