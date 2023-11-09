/*	NAME : M. SATYA SAI TEJA
    CLASS : CSE, 2ND YEAR
    ROLL : 20/11/EC/011
    DATE : 3 MARCH 2022
    QUESTION 2, C PROGRAM THAT PRINTS THE ADJACENCY LIST OF A GRAPH AND FEW OPERATIONS ON IT
*/

/*
// THIS IS AN INCOMPLETE CODE

#include <stdio.h>
#include <stdlib.h>
#define M 20

int x, y;
int N;
int V[M];

struct node
{   int v;
    struct node *next;
};

struct node *createNode(int);

struct graph
{   int numVertices;
    struct node **adjLists;
};

struct graph *G;

// CREATE NODE :
struct node *createNode(int w)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->v = w;
    newNode->next = NULL;
    return newNode;
}

// CREATE GRAPH :
struct graph *createGraph(int n)
{
    struct graph *G = malloc(sizeof(struct graph));
    G->numVertices = n;

    G->adjLists = malloc(n * sizeof(struct node *));

    for (int i = 1; i<=n; i++)
    { G->adjLists[i] = NULL; }

    return G;
}

// SEARCH NODE :
 void search(struct graph *G, int w)
{
    if (G->adjLists[w] == NULL)
        {  printf("\n Vertex is not available \n ");
           return;
        }

    for (int i = 1; i<=G->numVertices; i++)
    {   if (G->adjLists[i]->v == w)
        { printf("\n MATCH FOUND! \n");
        return;
        }
    }

    { printf("\n %d, NOT FOUND! \n", w); }
}

// DISPLAY ADJ LIST :
void display(struct graph *G)
{
    int w;
    for (w = 1; w<= G->numVertices; w++)
    {
        struct node *temp = G->adjLists[w];
        printf("\n Vertex %d \n: ", w);
        while (temp)
        {
            printf("%d -> ", temp->v);
            temp = temp->next;
        }
        printf("\n");
    }
}

// INSERT NODE :
void insertNode(int w)
{
    G->adjLists[N]->next = createNode(w);
}

// INSERT EDGE :
void insertEdge(struct graph *G, int w1, int w2)
{
    struct node *newNode;

    newNode = createNode(w2);
    newNode->next = G->adjLists[w1];
    G->adjLists[w1] = newNode;

    newNode = createNode(w1);
    newNode->next = G->adjLists[w2];
    G->adjLists[w2] = newNode;
}

// DELETE NODE :
void delNode(int w)
{


   
}



// DRIVER CODE :
int main()
{
   
}
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

typedef struct node {
    int vertex;
    struct node *next;
} Node;

typedef struct graph {
    Node *adj_list[MAX_VERTICES];
    int num_vertices;
} Graph;

// Function prototypes
void init_graph(Graph *g, int num_vertices);
void add_edge(Graph *g, int src, int dest);
void bfs(Graph *g, int start);

int main()
{
    Graph g;
    int num_vertices, i;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);

    init_graph(&g, num_vertices);

    printf("Enter the edges of the graph (in the form src dest):\n");
    for (i = 0; i < num_vertices - 1; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        add_edge(&g, src, dest);
    }

    printf("Enter the starting vertex for the BFS: ");
    int start;
    scanf("%d", &start);
    bfs(&g, start);

    return 0;
}

// Initializes the graph with the given number of vertices
void init_graph(Graph *g, int num_vertices)
{
    int i;
    g->num_vertices = num_vertices;

    // Set all adjacency lists to NULL
    for (i = 0; i < num_vertices; i++) {
        g->adj_list[i] = NULL;
    }
}

// Adds an edge from src to dest in the graph
void add_edge(Graph *g, int src, int dest)
{
    // Add an edge from src to dest
    Node *new_node = malloc(sizeof(Node));
    new_node->vertex = dest;
    new_node->next = g->adj_list[src];
    g->adj_list[src] = new_node;

    // Add an edge from dest to src
    new_node = malloc(sizeof(Node));
    new_node->vertex = src;
    new_node->next = g->adj_list[dest];
    g->adj_list[dest] = new_node;
}

// Performs a breadth first search on the graph starting from the given vertex
void bfs(Graph *g, int start)
{
    // Queue for BFS
    int queue[MAX_VERTICES];
    int front = 0;
    int rear = 0;

    // Array to keep track of visited vertices
    bool visited[MAX_VERTICES];

    // Initialize visited array
    int i;
    for (i = 0; i < g->num_vertices; i++) {
        visited[i] = false;
    }

    // Mark the current vertex as visited and enqueue it
   


