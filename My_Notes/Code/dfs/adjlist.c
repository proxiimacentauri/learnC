#include <stdio.h>
#include <stdlib.h>

struct node
{
  int valVertice;
  struct node *link;
};

struct graph
{
  int numVertices;
  struct node **adjLists;
};


struct node *createNode(int value)
{
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->valVertice = value;
  newNode->link = NULL;

  return newNode;
}

struct graph *createGraph(int vertices)
{
  struct graph *G = (struct graph *)malloc(sizeof(struct graph));

  G->numVertices = vertices;
  G->adjLists = (struct node **)malloc(vertices * sizeof(struct node));

  for (int i = 0; i < vertices; i++)
    G->adjLists[i] = NULL;

  return G;
}

void addEdge(struct graph* G, int src, int dest)
{
  struct node* newNode;

  // Add edge from source to destination
  newNode = createNode(dest);
  newNode->link = G->adjLists[src];
  G->adjLists[src] = newNode;

  // Add edge from destination to source
  newNode = createNode(src);
  newNode->link = G->adjLists[dest];
  G->adjLists[dest] = newNode;
}

void printGraph(struct graph* G)
{
  for (int v = 0; v < G->numVertices; v++)
  {
    struct node *temp = G->adjLists[v];
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
    struct graph *G = createGraph(4);
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