/*	NAME : M. SATYA SAI TEJA
    CLASS : CSE, 2ND YEAR
    ROLL : 20/11/EC/011
    DATE : 7 JUNE 2022
    QUESTION 8(ii), FIND SHORTEST PATH FROM A GIVEN SOURCE NODE TO ALL OTHER NODES IN A DAG
*/

#include <stdio.h>
#include <stdbool.h>
#define M 10
#define I 9999999


int x, y, w, s, A[M][M];
int N, E, S[M];
int D[M];
bool V[M];
int t = 1;
void display();
void dag_shp(int s, int D[M]);

// CREATE ADJ MATRIX OF GRAPH :
int create()
{
    int z = 1;
    for (x = 1; x <= N; x++)
        for (y = 1; y <= N; y++)
        {
            A[x][y] = 0; // Initializing all the elements of the array A with "0"
        }

    printf("\n If an edge exists between x and y such that (x -->-- y) enter the values of x, y and their weigth : ");

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
    printf("\n Enter the number of vertices (N) you want to insert : ");
    scanf("%d", &N);
    printf("\n Enter the number of Edges (E) you want to insert : ");
    scanf("%d", &E);

    create(A);
    printf("\n Enter the source node from which you want to find the shortest path : ");
    scanf("%d", &s);

    printf("\n");
    
    dag_shp(s, D);

    printf(" Vertex \t Distance from Source\n");
    for (int i = 1; i <= N; i++)
    {
        printf(" (%d) \t\t %d \n",i,D[i]);
    }

    return 0;
}

// STACK PUSH :
void push(int u)
{
    S[t] = u;
    t++;

    if(t>N)
    {
        t = N;
    }
    return;
}

// POP FUNCTION :
void pop()
{
    if (t != 0)
    {
        t--;
    }
    return;
}

// TOP FUNCTION :
int top()
{
    return S[t]; 
}

// DFS :
void DFS(int u)
{
    V[u] = true;                                                            
                                                                          
    for (int i = 1; i <= N; i++)
    {
        if (A[u][i] != 0 && !V[i])
        {
            DFS(i);
        }
    }
    push(u);
    return;
}

// RELAX FUNCTION :
void relax(int D[M], int n, int x)
{
    if (A[n][x] != 0)
    {
        if (D[x] > D[n] + A[n][x])
        {
            D[x] = D[n] + A[n][x];
        }
    }
}

// DAG SHORTEST PATH FUNCTION :
void dag_shp(int s, int D[M])
{
    for (x = 1; x <= N; x++)
    {
        V[x] = false;
    }

    for (x = 1; x <= N; x++)
    {
        if (!V[x])
        {
            DFS(x);
        }
    }

    for (x = 1; x <= N; x++)
    {
        D[x] = I;
    }

    D[s] = 0;

    while (t > 0)
    {
        int n = top();       
        pop();
        
        if(D[n] != I)
        {   
            for (x = 1; x <= N; x++)
            {
                relax(D, n, x);
            }
        }
    }

}

// example : 1 2 5 2 3 2 3 4 7 4 5 -1 5 6 -2 1 3 3 2 4 6 3 5 4 3 6 2 4 6 1 