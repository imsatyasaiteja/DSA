/*	NAME : M. SATYA SAI TEJA
    CLASS : CSE, 2ND YEAR
    ROLL : 20/11/EC/011
    DATE :  7 JUNE 2022
    QUESTION 7(ii), DIJKSTRA'S ALGORITHM TO FIND SHORTEST PATH FROM A GIVEN SOURCE NODE TO ALL OTHER NODES IN ADJ MATRIX GRAPH
*/

#include <stdio.h>
#include <stdbool.h>
#define M 10
#define I 9999999

int x, y, w, s, u, v, A[M][M];
int N, E, D[M];
bool V[M];
void display();
void dijkstra(int s);

// CREATE ADJ MATRIX OF GRAPH :
int create()
{
    int z = 1;
    for (x = 1; x <= N; x++)
        for (y = 1; y <= N; y++)
        {
            A[x][y] = 0; // Initializing all the elements of the array A with "0"
        }

    printf("\n If an edge exists between x and y such that (x -->-- y) enter the values of x, y and their weight : \n");

    while (z <= E)
    {
        printf("\n");
        printf("\t x = ");
        scanf("%d", &x);
        printf("\t y = ");
        scanf("%d", &y);
        printf("\t w = ");
        scanf("%d", &w);

        if (x == y)
        {
            printf("\n Same Vertex!, self loop is not possible in a simple undirected graph \n");
        }
        else if (x > N || y > N)
        {
            printf("\n Vertex x or y is greater the number of nodes");
        }
        else
        {
            A[x][y] = w; // For the given values of x and y, an edge is inserted
            A[y][x] = 0;
            z++;
        }
    }

    display(A); // The graph is displayed in the form of Adj matrix
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
            printf(" %d", A[x][y]);
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
    scanf("%d", &N);
    printf("\n Enter the number of Edges (E) you want to insert : ");
    scanf("%d", &E);

    create(A);
    printf("\n Enter the source node from which you want to find the shortest path : ");
    scanf("%d", &s);

    printf("\n");
    dijkstra(s);

    printf("Vertex \t\t Distance from Source\n");
    for (int i = 1; i <= N; i++)
    {    
        printf("(%d) \t\t %d\n", i, D[i]);
    }

    return 0;
}

// MIN DISTANCE FUNCTION :
int min_dist()
{
    int minDist = I;
    int minInd;

    for (int i = 1; i <= N; i++)
    {   if(V[i] == false && D[i] <= minDist)
        {
            minDist = D[i];
            minInd = i;
        }
    }
    return minInd;
}

// RELAX FUNCTION :
void relax(int u, int v)
{
    if(!V[v] && A[u][v] && D[u] != I && D[u] + A[u][v] < D[v])
    {
        D[v] = D[u] + A[u][v];
    }
}

// DIJKSTRA FUNCTION :
void dijkstra(int s)
{
    int e = 1;

    for (x = 1; x <= N; x++)
    {
        D[x] = I;                                                   // Mark D[] as Infinity
        V[x] = false;
    }

    D[s] = 0;                                                      // Distance from source vertex to itself is made zero
 
    while(e < N)
    {
        u = min_dist();
        V[u] = true;

        for (v = 1; v <= N; v++)
        {
            relax(u, v);
        }

        e++;
    }
}

// example : 1 2 1 2 3 1 3 4 2 4 5 3 5 6 2 3 6 1 2 4 4 1 4 6 1 5 7 4 6 2