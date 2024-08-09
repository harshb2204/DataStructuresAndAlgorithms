//kruskalsmatrix

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int parent[MAX];

int findparent(int i)
{
    while (i != parent[i])
    {
        i = parent[i];
    }
    return i;
}

void uni(int i, int j)
{
    int a = findparent(i);
    int b = findparent(j);
    parent[b] = a;
}

void krushkals(int G[][MAX], int v)
{

    int ne = 0;
    int a, b;

    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }

    while (ne < v - 1)
    {

        int min = 999;

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (G[i][j] != 0 && G[i][j] < min && findparent(i) != findparent(j))
                {
                    min = G[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        uni(a, b);

        printf("Edge %d :- %d %d => %d\n", ne++, a, b, min);
    }
}

int main()
{
    int v;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    int G[MAX][MAX];
    int u, w, z, numEdges;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            G[i][j] = 0;
        }
    }

    for (int i = 0; i < v; i++)
    {
        printf("Enter number of edges for vertex %d: ", i);
        scanf("%d", &numEdges);
        for (int j = 0; j < numEdges; j++)
        {
            printf("Enter edge (source destination) and weight: ");
            scanf("%d %d %d", &u, &w, &z);
            G[u][w] = G[w][u] = z;
        }
    }
    krushkals(G, v);
    return 0;
}