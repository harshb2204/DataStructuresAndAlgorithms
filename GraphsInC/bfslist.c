//bfslist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int vertex;
    struct Node *next;
};

// Queue implementation
struct Queue
{
    int capacity;
    int front, rear;
    int *array;
};

// Function to create a new queue
struct Queue *createQueue(int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return queue->front > queue->rear;
}

// Function to check if the queue is full
int isFull(struct Queue *queue)
{
    return queue->rear == queue->capacity - 1;
}

// Function to enqueue an element into the queue
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

// Function to dequeue an element from the queue
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

// BFS traversal using queue
void bfsList(struct Node *A[], int v)
{
    int visited[10];
    int st, w;

    printf("Enter start vertex: ");
    scanf("%d", &st);

    struct Queue *queue = createQueue(100);

    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }

    enqueue(queue, st);
    visited[st] = 1;

    while (!isEmpty(queue))
    {
        w = dequeue(queue);
        printf("%d ", w);

        struct Node *p = A[w];

        while (p != NULL)
        {
            if (visited[p->vertex] == 0)
            {
                enqueue(queue, p->vertex);
                visited[p->vertex] = 1;
            }
            p = p->next;
        }
    }

    free(queue->array);
    free(queue);
}

// Function to create adjacency list
void AdjList(struct Node *A[], int v)
{
    int u, w;
    char ch[4];

    struct Node *p;
    struct Node *newV;

    for (int i = 0; i < v; i++)
    {
        A[i] = NULL;
    }

    do
    {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &u, &w);

        newV = (struct Node *)malloc(sizeof(struct Node));
        newV->vertex = w;
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

        newV = (struct Node *)malloc(sizeof(struct Node));
        newV->vertex = u;
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

int main()
{
    struct Node *G[10];
    int v;

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    AdjList(G, v);
    bfsList(G, v);

    return 0;
}
