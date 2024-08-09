
//kruskalslist
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

int parent[MAX];

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

int findParent(int i)
{
    while (i != parent[i])
    {
        i = parent[i];
    }
    return i;
}

void uni(int i, int j)
{
    int a = findParent(i);
    int b = findParent(j);
    parent[b] = a;
}

void kruskals(struct Node *A[], int v)
{
    int min, a, b, ne = 0, minWeight = 0;
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }
    while (ne < v - 1)
    {
        min = 999;
        for (int i = 0; i < v; i++)
        {
            struct Node *p = A[i];
            while (p != NULL)
            {
                if (p->weight < min && findParent(p->vertex) != findParent(i))
                {
                    min = p->weight;
                    a = i;
                    b = p->vertex;
                }
                p = p->next;
            }
        }
        uni(a, b);
        printf("Edge %d - %d => %d\n", a, b, min);
        ne++;
        minWeight += min;
    }
    printf("Minimum cost = %d\n", minWeight);
}

int main()
{
    int v;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    struct Node *G[MAX];
    adjList(G, v);

    printf("\n\n\n");
    kruskals(G, v);
    return 0;
}
