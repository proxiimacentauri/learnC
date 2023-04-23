#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node
{
    int valVertice;
    struct node *link;
};

struct graph
{
    int numVertice;
    struct node **adjList;
};

struct node *createNode(int value);
struct graph *createGraph(int num_of_vertices);
void addEdge(struct graph *G, int src, int dest);


void printGraph(struct graph* G)
{
  for (int v = 0; v < G->numVertice; v++)
  {
    struct node *temp = G->adjList[v];
    printf("\n Vertex %d: ", v);

    while (temp != NULL)
    {
      printf("%d -> ", temp->valVertice);
      temp = temp->link;
    }
    printf("\n");
  }
}

int main()
{
    struct graph *G = createGraph(5);
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
    printGraph(G);
    return 0;
}


void addEdge(struct graph *G, int src, int dest)
{
    struct node *tmpNode;

    // Connect Source to Destination
    tmpNode = createNode(src);
    tmpNode->link = G->adjList[dest]; // New Node should point to where he pointer of adjList points
    G->adjList[dest] = tmpNode; // after node is init... adjList should point to new node

    // Connect Destination to Source
    tmpNode = createNode(dest);
    tmpNode->link = G->adjList[src]; // New Node should point to where he pointer of adjList points
    G->adjList[src] = tmpNode; // after node is init... adjList should point to new node
}

struct graph *createGraph(int num_of_vertices)
{
    // Get Memory allocated to store info of Graph
    struct graph *G = (struct graph *)malloc(sizeof(struct graph));
    //assert(G != NULL);

    G->numVertice = num_of_vertices;
    G->adjList = (struct node **)malloc(num_of_vertices * sizeof(struct node));
    // We need to create a pointer which points to linked list * num_of_vertices

    for(int i = 0; i < num_of_vertices; i++)
    {
        // Initially the double pointer should point to Nothing
        G->adjList[i] = NULL;
    }

    return G;
}

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    //assert(newNode != NULL);

    newNode->valVertice = value;
    newNode->link = NULL;

    return newNode;
}



