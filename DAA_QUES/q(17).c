/*	NAME : M. SATYA SAI TEJA
    CLASS : CSE, 2ND YEAR
    ROLL : 20/11/EC/011
    DATE : 28 FEBRUARY 2022
    QUESTION 1, C PROGRAM THAT PRINTS THE ADJACENCY MATRIX OF A GRAPH AND FEW OPERATIONS ON IT
*/

#include<stdio.h>
#include<stdlib.h>
#define M 20

int x, y, h, t;
int N;
int E;
int A[M][M];                                                                    // A[M][M] is the adj matrix of the graph
int V[M], Q[M], R[M];                                                           // V[M] is visited nodes in DFS, R[M] is visited, Q[M] is queue in BFS 

// FUNCTION DECLARATIONS :
int create();                                                                   // This function creates a Graph in the form of Adj matrix
void search(int w);                                                             // This function is used to search if a particular node is present
void display();                                                                 // This function is used to display the Adj matrix
void insertNode();                                                              // This function is used to insert a new node in the graph
void insertEdge();                                                              // This function is used to insert a new edge in the graph
void deleteNode(int w);                                                         // This function deletes a node in the graph
void DFS(int w);                                                                // The DFS sequence of the graph from a particular node is obtained
void BFS(int u);                                                                // The BFS sequence of the graph from a particular node is obtained


// DRIVER CODE :
void main()
{   
    printf("\n Enter the number of Nodes (N) you want to insert : ");
    scanf("%d", &N);
    printf("\n Enter the number of Edges (E) you want to insert : ");
    scanf("%d", &E);

    create(A);

    while (1)
    {
        int a, w, u;
        printf("\n 1) Search a node\n 2) Insert a node\n 3) Insert an edge\n 4) Delete a node\n 5) Apply DFS\n 6) Apply BFS\n 7) Exit\n");
        printf("\n Enter your choice : ");
        scanf("%d",&a);
        switch (a)
        {
        case 1:
            printf(" Enter the node you want to search : ");
            scanf("%d",&w);
            search(w);
            break;
        case 2:
            printf(" New node is inserted ");
            insertNode();
            break;
        case 3:
            printf(" Enter the node values between which you want an edge : \n");
            insertEdge();
            break;
        case 4:
            printf(" Enter the node you want to delete : ");
            scanf("%d",&w);
            deleteNode(w);
            break;
        case 5:
            printf(" Enter the number on which you want to Apply DFS : ");
            scanf("%d",&w);
            printf("\n");
            DFS(w);
            printf("\n");
            for (x = 1; x <= N; x++)
            {   V[x] = 0;                                                           // We are clearing all the visited nodes to use them next time
            }
            break;
        case 6:
            h = 0, t = 1;
            printf(" Enter the number on which you want to Apply BFS : ");
            scanf("%d",&u);
            printf("\n");
            BFS(u);
            printf("\n");
            for (x = 1; x <= N; x++)
            {
                Q[x] = 0;                                                           // We are clearing all the elements in queue to use it next time
                R[x] = 0;                                                           // We are clearing all the visited nodes to use them next time
            }
                break;
        case 7:
            printf("\n PROGRAM TERMINATED \n");
            exit(0);
        default:
            printf("\n Please enter a valid input \n");
            break;
        }        
    }
    return ;
}

// CREATE ADJ MATRIX OF GRAPH :
int create()
{
    int z = 1;
    for (x = 1; x <= N; x++)
        for (y = 1; y <= N; y++)
        {
            A[x][y] = 0;                                                        // Initializing all the elements of the array A with "0" 
        }

    while (z <= E)
    {
        printf("\n Enter the node values between which you want an edge : \n");
        printf("\t x = ");
        scanf("%d",&x);                                                        
        printf("\t y = ");
        scanf("%d",&y);

        if ((x > N) || (y > N))
        {   printf("\n Vertex is not possible! \n");
            insertEdge();
            return 0;
        }

        if (x == y)
        {
            printf("\n Same Vertex!, self loop is not possible in a simple undirected graph \n");
        }
        else
        {   A[x][y] = 1;                                                       // For the given values of x and y, an edge is inserted
            A[y][x] = 1;
            z++;
        }
    }

    display(A);                                                               // The graph is displayed in the form of Adj matrix
    return A[M][M];
}

// SEARCH NODE :
void search(int w) 
{
    int z = 1;
    int y = 1;

    while (z<=N)
    {   if(w==z)
        {   printf(" Node found, Associated edges are : ");
            while(y<=N)
            { if(A[w][y] == 1)
              { printf("(%d) ",y);}
              y++; 
            }
            printf("\n");
            return;
        }  
        else
        {  z++; }
    }
    printf("Node not found");
    return;
}

// DISPLAY ADJ MATRIX :
void display()
{   printf("\n The Adj matrix representation of graph is as follows : \n\n");
    for (int x = 1; x <= N; x++)
    {
    for (int y = 1; y <= N; y++)
    {
        printf(" %d",A[x][y]);
    }
    printf("\n");
    }
    return;
}

// INSERT NODE :
void insertNode()
{
    N++;   
    for (x = 1; x <= N; ++x)
    {
        A[x][N] = 0;
        A[N][x] = 0;
    }
    display(A);
}

// INSERT EDGE :
void insertEdge()
{
    printf("\t x = ");
    scanf("%d", &x);
    printf("\t y = ");
    scanf("%d", &y);

    if ((x > N) || (y > N))
    { printf("\n Vertex is not possible! \n");
      return;
    }

    if (x == y)
    { printf("\n Same Vertex!, self loop is not possible in a simple undirected graph \n");
    }
    else
    {
        A[x][y] = 1;
        A[y][x] = 1;
        display(A);
    }
    
}

// DELETE NODE :
void deleteNode(int w)
{
        if (w > N)
        {   printf("\n Vertex is not present!");
            return;
        }
        else
        {   while (w <= N)
            {
                for (x = 1; x <= N; x++)
                {
                    A[x][w] = A[x][w + 1];
                }
                for (x = 1; x <= N; x++)
                {
                    A[w][x] = A[w + 1][x];
                }
                w++;
            }
           N--;
        }
        display(A);
}

// DFS :
void DFS(int w)
{   
    V[w] = 1;                                                                   // Visited array V gets marked 1 whenever a new node "w" is visited
    printf(" %d ->", w);
    for (x = 1; x <= N; x++)
    {  if (A[w][x] == 1 && V[x] == 0)
        {   int y = w;                                                         // variable y stores the value of previous node "w" for future use
            DFS(x);

            // if the traversal ends at a node without completion, we go back to previous node and explore it

            for (x = 1; x <= N; x++)
            {   if (A[y][x] == 1 && V[x] == 0)
                {
                    printf(" Back to");
                    DFS(y);
                }
            }
        }
    }
    return;
}

// BFS :
void BFS(int u)
{   
    R[u] = 1;                                                               // The visited array R gets marked 1 whenever a new node "u" is visited
    if(u != 0)
    { printf(" %d ->", u); }
    h++;                                                                    // Here "h" is the head of Q[M] which was initialized as "0" previously
    for (int i = 1; i<= N; i++)
    {   if(A[u][i] == 1 && R[i] != 1)
        {
            Q[t] = i;                                                       // Here "t" is the tail of Q[M] which was initialized as "1" previously
            t++;
        }
    }

    while(h<=t)
   { if (h <= t && R[Q[h]] != 1)
    {   BFS(Q[h]); }
    h++;
   }

    return;
}




  