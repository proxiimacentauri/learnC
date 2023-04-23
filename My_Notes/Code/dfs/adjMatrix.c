#include<stdio.h>
#include<stdlib.h>

struct graph
{
    int V;
    int E;
    int *adjMatrix;
};

void createAdjMatrix(void);


int main()
{
    printf("\n\n---------------Create Adjecency Matrix for Graph---------------\n\n");
    createAdjMatrix();
    return 0;
}

void createAdjMatrix(void)
{
    struct graph *G = (struct graph *)malloc(sizeof(struct graph));
    if(G == NULL) {printf("\nMemory was NOT allocated. (Err:createAdjMatrix)\n");exit(1);}

    printf("\nEnter Number of Vertices and Edges in the Graph: ");
    scanf("%d %d", &G->V, &G->E);

    //G->adjMatrix = malloc(sizeof(int) * G->V * G->E); // calloc(G->V * G->E, sizeof(int)); // initializes adjMatrix with All 0's
    G->adjMatrix = calloc(G->V * G->V, sizeof(int));

    int i, a, b;
    for(i = 0; i < G->E; i++)
    {
        printf("\nEnter the Graph Node relationship in Pairs: ");
        scanf("%d %d", &a, &b);
        G->adjMatrix[a*G->V + b] = 1;
        G->adjMatrix[b*G->V + a] = 1;
    }
}