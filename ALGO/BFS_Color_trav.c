/*	NAME : M. SATYA SAI TEJA
    CLASS : CSE, 2ND YEAR
    ROLL : 20/11/EC/011
    DATE : 12 JUNE 2022
    CODE FOR BFS TRAVERSAL
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10
#define I 9999999

int x, y, s;
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
    int u;
    struct node *v;
};

struct node *temp;

// EDGE STRUCTURE :
struct edge
{
    int s, d;
};

// CREATE ADJ LIST OF A GRAPH :
struct graph *create(struct edge E[], int n, int e)
{
    struct graph *g = (struct graph *)malloc(sizeof(struct graph)); // Allocating storage to a graph called g

    for (int i = 1; i <= n; i++)
    {
        g->A[i] = NULL; 
    }

    for (int i = 1; i <= e; i++)
    {
        int s = E[i].s;
        int d = E[i].d;

        struct node *newNode = (struct node *)malloc(sizeof(struct node)); // Allocating storage to a node called newNode
        newNode->u = d;

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
            printf(" %d -> %d \t", i, temp->u);
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
        }
    }

    struct graph *g = create(E, n, e);

    printf("\n");
    display(g, n);


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

