
#include <stdio.h>
#include <stdlib.h>

typedef struct DEQueue
{
    int size;
    int front_index;
    int rear_index;
    int *arr;
} DEQueue;

int IsFull(DEQueue *q)
{
    if (q->rear_index == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int IsEmpty(DEQueue *q)
{
    if (q->front_index == q->rear_index)
    {
        return 1;
    }
    return 0;
}

void ENQueueRear(DEQueue *d, int val)
{
    if (IsFull(d))
    {
        printf("Double Ended Queue is OverFlow\n");
    }
    else
    {
        d->rear_index++;
        d->arr[d->rear_index] = val;
        printf("ENQueueing Rear Element %d\n", val);
    }
}

int DequeueFront(DEQueue *d)
{
    int x = -1;
    if (IsEmpty(d))
    {
        printf("Double Ended Queue is UnderFlow\n");
    }
    else
    {
        d->front_index++;
        x = d->arr[d->front_index];
        printf("DEQueueing or DELETING Front element: %d\n", x);
    }
    return x;
}

void EnqueueFront(DEQueue *d, int val)
{
    if (IsFull(d) || d->front_index == -1)
    {
        printf("Double Ended Queue has no space to insert element in the front side\n");
    }
    else
    {
        d->arr[d->front_index] = val;
        d->front_index--;
        printf("ENQueueing or ADDING Front element: %d\n", val);
    }
}

int DEQueueRear(DEQueue *d)
{
    int x;
    if (IsEmpty(d))
    {
        printf("Double Ended Queue has no element");
    }
    else
    {
        x = d->arr[d->rear_index];
        d->rear_index--;
        printf("DEQueuing or DELETING Rear element:%d\n", x);
    }
    return x;
}

void Display(DEQueue *d)
{
    for (int i = 0; i <= d->rear_index; i++)
    {
        printf("Element is: %d\n", d->arr[i]);
    }
}

int main()
{
    DEQueue q;
    q.size = 5;
    q.front_index = q.rear_index = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    ENQueueRear(&q, 54);
    ENQueueRear(&q, 44);
    ENQueueRear(&q, 76);
    ENQueueRear(&q, 87);

    printf("\n");
    DequeueFront(&q);
    DEQueueRear(&q);

    printf("\n");
    EnqueueFront(&q, 65);

    printf("\n");
    Display(&q);

    return 0;
}
