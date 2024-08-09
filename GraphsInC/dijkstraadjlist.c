//dijsktralist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct Node
{
    int vertex;
    int weight;
    struct Node *next;
};

void adjList(struct Node *A[], int v)
{
    int u, w, weight;
    char ch[4];
    struct Node *p;
    struct Node *newV;

    for (int i = 0; i < v; i++)
    {
        A[i] = NULL;
    }

    do
    {
        printf("Enter edge (source destination weight): ");
        scanf("%d %d %d", &u, &w, &weight);

        newV = (struct Node *)malloc(sizeof(struct Node));
        newV->vertex = w;
        newV->weight = weight;
        newV->next = NULL;

        p = A[u];
        if (p == NULL)
        {
            A[u] = newV;
        }
        else
        {
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = newV;
        }

        // Adding the edge in the reverse direction for undirected graph
        newV = (struct Node *)malloc(sizeof(struct Node));
        newV->vertex = u;
        newV->weight = weight;
        newV->next = NULL;

        p = A[w];
        if (p == NULL)
        {
            A[w] = newV;
        }
        else
        {
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = newV;
        }

        printf("Do you want to continue adding edges? (yes/no): ");
        scanf("%s", ch);
    } while (strcmp(ch, "yes") == 0);
}

int minvertex(int dist[], int visited[], int v)
{
    int minimum = 9999;
    int idx = -1;

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0 && dist[i] < minimum)
        {
            minimum = dist[i];
            idx = i;
        }
    }
    return idx;
}

void display(int dist[], int start, int v)
{
    for (int i = 0; i < v; i++)
    {
        printf("Distance from %d to %d is %d\n", start, i, dist[i]);
    }
}

void dijkstras(struct Node *A[], int v)
{
    int visited[v];
    int dist[v];
    int st;

    for (int i = 0; i < v; i++)
    {
        dist[i] = 9999;
        visited[i] = 0;
    }

    printf("Enter start vertex: ");
    scanf("%d", &st);

    dist[st] = 0;

    for (int i = 0; i < v - 1; i++)
    {
        int f = minvertex(dist, visited, v);
        if (f == -1) // No more vertices to process
            break;
        visited[f] = 1;

        struct Node *p = A[f];
        while (p != NULL)
        {
            if (visited[p->vertex] == 0 && dist[p->vertex] > dist[f] + p->weight)
            {
                dist[p->vertex] = dist[f] + p->weight;
            }
            p = p->next;
        }
    }

    display(dist, st, v);
}

int main()
{
    int v;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    struct Node *G[MAX];
    adjList(G, v);
    dijkstras(G, v);

    return 0;
}
