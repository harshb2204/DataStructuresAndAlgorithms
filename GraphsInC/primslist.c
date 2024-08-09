//primslist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct Node {
    int vertex;
    int wt;
    struct Node *next;
};

void adjList(struct Node *A[], int v) {
    int u, w, weight;
    char ch[4];
    struct Node *p;
    struct Node *newV;

    for (int i = 0; i < v; i++) {
        A[i] = NULL;
    }

    do {
        printf("Enter edge (source destination weight): ");
        scanf("%d %d %d", &u, &w, &weight);

        // Add edge from u to w
        newV = (struct Node *)malloc(sizeof(struct Node));
        newV->vertex = w;
        newV->wt = weight;
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

        // Add edge from w to u (undirected graph)
        newV = (struct Node *)malloc(sizeof(struct Node));
        newV->vertex = u;
        newV->wt = weight;
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

void display(struct Node *A[], int v) {
    for (int i = 0; i < v; i++) {
        struct Node *p = A[i];
        printf("%d |", i);
        while (p != NULL) {
            printf(" %d(wt=%d) ->", p->vertex, p->wt);
            p = p->next;
        }
        printf(" NULL\n");
    }
}

int FindMin(int dist[], int visited[], int v) {
    int min = 999, index = -1;

    for (int i = 0; i < v; i++) {
        if (visited[i] == 0 && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void prims(struct Node *A[], int v) {
    int visited[MAX];
    int parent[MAX];
    int dist[MAX];

    for (int i = 0; i < v; i++) {
        dist[i] = 999;
        parent[i] = -1;
        visited[i]=0;
    }
    dist[0] = 0;

    for (int i = 0; i < v - 1; i++) {
        int u = FindMin(dist, visited, v);
        visited[u] = 1;
        struct Node *p = A[u];
        while (p != NULL) {
            if (visited[p->vertex] == 0 && p->wt < dist[p->vertex]) {
                dist[p->vertex] = p->wt;
                parent[p->vertex] = u;
            }
            p = p->next;
        }
    }

    printf("Edges in Minimum Spanning Tree:\n");
    for (int i = 1; i < v; i++) {
        printf("%d - %d\n", parent[i], i);
    }
}

int main() {
    int v;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    struct Node *G[MAX];
    adjList(G, v);
    display(G, v);
    prims(G, v);
    return 0;
}
