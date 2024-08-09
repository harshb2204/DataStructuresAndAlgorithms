//dfs matrix

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int capacity;
    int top;
    int *arr;
};

struct stack *createStack(int capacity)
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st->capacity = capacity;
    st->top = -1;
    st->arr = (int *)malloc(sizeof(int) * st->capacity);
    return st;
}

void push(struct stack *st, int data)
{
    if (st->top >= st->capacity - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    st->arr[++st->top] = data;
}

int isEmpty(struct stack *st)
{
    return st->top == -1;
}

int pop(struct stack *st)
{
    if (isEmpty(st))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return st->arr[st->top--];
}

void DFS(int v, int g[v][v])
{
    int visited[v], start, w;
    struct stack *st = createStack(v);
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
    printf("Enter start vertex : ");
    scanf("%d", &start);
    visited[start] = 1;
    push(st, start);
    while (!isEmpty(st))
    {
        w = pop(st);
        printf("%d ", w);
        for (int i = 0; i < v; i++)
        {
            if (g[w][i] == 1 && visited[i] == 0)
            {
                push(st, i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int n, e, u, v;
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    int adjMatrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
    printf("Enter number of edges : ");
    scanf("%d", &e);
    for (int i = 0; i < e; i++)
    {
        printf("Enter edge (start - end) : ");
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = adjMatrix[v][u] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    DFS(n, adjMatrix);

        return 0;
}
