/*	NAME : M. SATYA SAI TEJA
    CLASS : CSE, 2ND YEAR
    ROLL : 20/11/EC/011
    DATE : 8 JUNE 2022
    QUESTION 7(i) DIJKSTRA'S ALGO TO FIND SHORTEST PATH FROM SOURCE NODE TO ALL OTHER NODES IN ADJ LIST GRAPH
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10
#define I 9999999

int x, y, w, s;
int u, v, n, e, D[N];
bool V[N];

// GRAPH STRUCTURE :
struct graph
{
    struct node *A[N];
};

void dijkstra(struct graph *g, int s);

// NODE STRUCTURE :
struct node
{
    int u, w;
    struct node *v;
};

struct node *temp;

// EDGE STRUCTURE :
struct edge
{
    int s, d, w;
};

// CREATE ADJ LIST OF A GRAPH :
struct graph *create(struct edge E[], int n, int e)
{
    struct graph *g = (struct graph *)malloc(sizeof(struct graph)); 

    for (int i = 1; i <= n; i++)
    {
        g->A[i] = NULL; 
    }

    for (int i = 1; i <= e; i++)
    {
        int s = E[i].s;
        int d = E[i].d;
        int w = E[i].w;

        struct node *newNode = (struct node *)malloc(sizeof(struct node)); 
        newNode->u = d;
        newNode->w = w;

        newNode->v = g->A[s];

        g->A[s] = newNode;
    }

    return g;
}

// DISPLAY ADJ LIST :
void display(struct graph *g, int n)
{
    printf("\n The Adj list representation of graph is as follows : \n\n");
    for (int i = 1; i <= n; i++)
    {
        struct node *temp = g->A[i];
        while (temp != NULL)
        {
            printf(" %d -> %d (weight : %d)\t", i, temp->u, temp->w);
            temp = temp->v;
        }
        printf("\n");
    }
}

// MAIN FUNCTION :
int main(void)
{
    int x, y, z, s;
    printf("\n Enter the number of vertices (n) you want to insert : ");
    scanf("%d", &n);
    printf("\n Enter the number of Edges (e) you want to insert : ");
    scanf("%d", &e);

    struct edge E[N];
    printf("\n Enter the vertex values between which you want an edge and their weigths : \n");
    for (int i = 1; i <= e; i++)
    {
        printf("\n");
        printf("\t x = ");
        scanf("%d", &x);
        printf("\t y = ");
        scanf("%d", &y);
        printf("\t w = ");
        scanf("%d", &z);

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
            E[i].s = x;
            E[i].d = y;
            E[i].w = z;
        }
    }

    struct graph *g = create(E, n, e);

    printf("\n");
    display(g, n);

    printf("\n Enter the index from which you want to find the minimum spanning tree : ");
    scanf("%d", &s);
    printf("\n");
    dijkstra(g, s);

    return 0;
}

// MIN DISTANCE FUNCTION :
int min_dist()
{
    int minDist = I;
    int minInd;

    for (int i = 1; i <= n; i++)
    {
        if (V[i] == false && D[i] <= minDist)
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
    if (!V[v] && D[u] != I && D[u] + temp->w < D[v])
    {
        D[v] = D[u] + temp->w ;
    }
}

// DIJKSTRA :
void dijkstra(struct graph *g, int s)
{
    bool V[N];
    int q = 1;

    for (x = 1; x <= n; x++)
    {
        D[x] = I; 
        V[x] = false;
    }

    D[s] = 0; 

    while (q < n)
    {
        u = min_dist();
        V[u] = true;

        for (int i = 1; i <= n; i++)
        {
            if (u == g->A[i]->u)
            {
                temp = g->A[i];
            }
        }

        for (v = 1; v <= n; v++)
        {  
            relax(temp->u, v);
        }

        q++;
    }
}

