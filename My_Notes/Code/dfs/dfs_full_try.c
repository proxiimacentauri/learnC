#include<stdio.h>
#include<stdlib.h>

// Create a Linked List structure for adjacency list
struct node
{
    int valVertice;
    struct node *link;
};

// Create a structure for Graph
/*
    number of vertices
    visited (bool value)
    double pointer for adjlist
*/
struct graph
{
    int numVertices;
    int *visited;
    struct node **adjlist;
};

// Create a New Node in Adjacency List
struct node *createNode(int value);

// Create a Graph
struct graph *createGraph(int num_vertices);

// Create an Edge in the Graph
void addEdge(struct graph *G, int src, int dest);

// Depth First Search (DFS)
void dfs(struct graph *G, int starting_node);

int main ()
{
    struct graph *G = createGraph(5);
    printf("\n------Graph Created-----\n");
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 0, 5);
    addEdge(G, 1, 0);
    addEdge(G, 1, 2);
    addEdge(G, 2, 1);
    addEdge(G, 2, 0);
    addEdge(G, 2, 3);
    addEdge(G, 3, 2);
    addEdge(G, 3, 5);
    addEdge(G, 3, 4);
    addEdge(G, 4, 3);
    addEdge(G, 5, 0);
    addEdge(G, 5, 3);
    printf("\n------Added Edges Created-----\n");
    printf("\n------Run DFS-----\n");
    dfs(G, 0);
    printf("\n\n");
    return 0;
}

struct node *createNode(int value)
{
    // Create a Linked List Node
    // - Points to NULL
    // - Assign value to Node

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode == NULL) {printf("\nMemory was NOT allocated (Err:createNode)\n");exit(1);}

    newNode->valVertice = value;
    newNode->link = NULL;

    return newNode;
}

struct graph *createGraph(int num_vertices)
{
    // Create a Graph
    // - Assign Num of Vertices
    // - Assign Visited = 0
    // - Allocate memory for adjList for ALL Vertices
    // - initialize All adjList pointers to NULL

    struct graph *G = (struct graph *)malloc(sizeof(struct graph));
    if(G == NULL) {printf("\nMemory was NOT allocated (Err:createGraph)\n");exit(1);}

    G->numVertices = num_vertices;
    G->visited = (int *)malloc(num_vertices * sizeof(int));
    if(G->visited == NULL) {printf("\nMemory was NOT allocated (Err:createGraph(G->visited))\n");exit(1);}
    G->adjlist = (struct node **)malloc(num_vertices * sizeof(struct node));
    if(G->adjlist == NULL) {printf("\nMemory was NOT allocated (Err:createGraph(G->adjlist))\n");exit(1);}

    for(int i = 0; i < num_vertices; i++)
        G->adjlist[i] = NULL;

    return G;
}

void addEdge(struct graph *G, int src, int dest)
{
    // Assume a Undirected Graph (Bi-Directional)
    struct node *tmp;

    // Connect Source --> Destination
    tmp = createNode(src);        // tmp points to a NEW source Node
    tmp->link = G->adjlist[dest]; // The source node should point to the Destination
    G->adjlist[dest] = tmp;       //

    // Connect Destination --> Source
    tmp = createNode(dest);
    tmp->link = G->adjlist[src];
    G->adjlist[src] = tmp;
}

void dfs(struct graph *G, int vertice)
{
    // get a pointer to all the neighbouring connected nodes of this vertice
    // which are stored in a linked list
    struct node *NV = G->adjlist[vertice];

    // Print and Mark the current vertice as visited in the graph
    G->visited[vertice] = 1;
    printf(" % 3d ", vertice);

    // Loop till we reach the end of the linked list
    while(NV != NULL)
    {
        // save value of the neighbouring element
        int valNV = NV->valVertice;

        // check if that element is visited
        // if NOT visited Run DFS on All the connected neighbouring nodes
        if(G->visited[valNV] == 0)
            dfs(G, valNV);

        // move on to the next node in the linked list
        NV = NV->link;
    }
}