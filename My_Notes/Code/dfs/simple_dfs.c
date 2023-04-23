#include<stdio.h>


int visited[5] = {0,0,0,0,0};
int G[5][5] = {
    {0,0,0,0,1},
    {1,0,1,0,1},
    {0,0,0,1,0},
    {1,0,0,0,0},
    {0,0,0,0,1},
};

void DFS(int graph_element)
{
    printf("% 3d ", graph_element);
    visited[graph_element] = 1;        // We set it to 1 because we have visited it
    for(int j = 0; j < 5; j++)
    {
        // if an Edge exsists and its NOT visited --> DFS it
        if(G[graph_element][j] == 1 && !visited[j])
        {
            DFS(j);
        }
    }
}


int main()
{
    printf("\n\n------------Simple DFS----------\n\n");
    DFS(0);
    printf("\n\n");
    return 0;
}