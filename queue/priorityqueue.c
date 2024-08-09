#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

int dequeue(struct Queue *q)
{
    int x = -1;

    if (q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void Display(struct Queue q)
{
    int i;

    for (i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

void enqueue(struct Queue *q, int x)
{
    int pos;

    if (q->rear == q->size - 1)
    {
        printf("Queue is full");
    }
    else
    {
        pos = q->rear;
        q->rear++;
        while (pos >= 0 && q->Q[pos] >= x)
        {
            q->Q[pos + 1] = q->Q[pos];
            pos--;
        }
        q->Q[pos + 1] = x;
        if (q->front == -1)
        {
            q->front++;
        }
    }
}

int main()
{

    struct Queue q;
    create(&q, 5);
    enqueue(&q, 4);
    enqueue(&q, 4);
    enqueue(&q, 2);
    enqueue(&q, 6);
    enqueue(&q, 1);
    Display(q);

    return 0;
}