//bfs matrix
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int capacity;
    int front, rear;
    int *array;
};


struct Queue *createQueue(int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}


int isEmpty(struct Queue *queue)
{
    return queue->rear < queue->front;
}


int isFull(struct Queue *queue)
{
    return queue->rear == queue->capacity - 1;
}


void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    queue->rear++;
    queue->array[queue->rear] = item;
}


int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front++;

    return item;
}

void BFS(int v, int g[v][v]) // matrix
{
    int visited[v], start, w;
    struct Queue *q = createQueue(v);
    printf("Enter start vertex : ");
    scanf("%d", &start);
    enqueue(q, start);
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
    visited[start] = 1;
    while (!isEmpty(q))
    {
        w = dequeue(q);
        printf("%d ", w);
        for (int i = 0; i < v; i++)
        {
            if (g[w][i] == 1 && visited[i] == 0)
            {
                enqueue(q, i);
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

    BFS(n, adjMatrix);

    return 0;
}
