//dijsktramatrix

#include <stdio.h>
#include <stdlib.h>

void display(int dist[], int startVertex, int v)
{
    for (int i = 0; i < v; i++)
    {
        printf("Distance from %d to %d is %d\n", startVertex, i, dist[i]);
    }
}

int findMinDist(int dist[], int visit[], int v)
{
    int min = 999, index = -1;
    for (int i = 0; i < v; i++)
    {
        if (visit[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstras(int G[][10], int v, int startVertex)
{
    int visit[10], dist[10];
    int i, j, u;

    for (i = 0; i < v; i++)
    {
        dist[i] = 999;
        visit[i] = 0;
    }

    dist[startVertex] = 0;

    for (i = 0; i < v - 1; i++)
    {
        u = findMinDist(dist, visit, v);
        visit[u] = 1;

        for (j = 0; j < v; j++)
        {
            if (visit[j] == 0 && G[u][j] != 999 && dist[u] + G[u][j] < dist[j])
            {
                dist[j] = dist[u] + G[u][j];
            }
        }
    }

    display(dist, startVertex, v);
}

int main()
{
    int v, u, w, weight;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    int G[10][10];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            G[i][j] = 999;
        }
    }

    int numEdges;
    printf("Enter number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++)
    {
        printf("Enter edge (source destination weight): ");
        scanf("%d %d %d", &u, &w, &weight);
        G[u][w] = weight;
    }

    int startVertex;
    printf("Enter start vertex: ");
    scanf("%d", &startVertex);

    dijkstras(G, v, startVertex);

    return 0;
}
