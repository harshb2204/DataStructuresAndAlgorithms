//primsmatrix
#include <stdio.h>
#include <stdlib.h>
int findMinDist(int dist[], int visit[], int v)
{
    int index, min = 999;
    for (int i = 0; i < v; i++)
    {
        if (visit[i] == 0 && min > dist[i])
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void displayMST(int parent[], int G[][10], int v)
{
    printf("Edge   Weight\n");
    for (int i = 1; i < v; i++)
        printf("%d - %d    %d \n", parent[i], i, G[i][parent[i]]);
}

void Prims(int G[][10], int v)
{
    int visit[10], parent[10], dist[10];
    int i, j, u;
    for (i = 0; i < v; i++)
    {
        parent[i] = -1;
        dist[i] = 999;
        visit[i] = 0;
    }
    dist[0] = 0;
    for (i = 0; i < v - 1; i++)
    {
        u = findMinDist(dist, visit, v);
        visit[u] = 1;
        for (j = 0; j < v; j++)
        {
            if (G[u][j] != 999 && visit[j] == 0 && G[u][j] < dist[j])
            {
                dist[j] = G[u][j];
                parent[j] = u;
            }
        }
    }
    displayMST(parent, G, v);
}

int main()
{
    // Example usage
    int G[10][10] = {{998, 2, 998, 6, 998},
                     {2, 998, 3, 8, 5},
                     {998, 3, 998, 998, 7},
                     {6, 8, 998, 998, 9},
                     {998, 5, 7, 9, 998}};
    int v = 5; // Number of vertices
    Prims(G, v);
    return 0;
}
