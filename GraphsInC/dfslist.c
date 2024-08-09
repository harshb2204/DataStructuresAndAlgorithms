//dfslist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int vertex;
    struct Node *next;
};

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
    if (st->top >= st->capacity)
    {
        return;
    }
    st->arr[++st->top] = data;
}

int isEmpty(struct stack *st)
{
    if (st->top < 0)
    {
        return 1;
    }
    return 0;
}

int pop(struct stack *st)
{
    if (isEmpty(st))
    {
        return -1;
    }
    int item = st->arr[st->top];
    st->top--;
    return item;
}

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

void DFSlist(struct Node *A[], int v)
{
    struct stack *s = createStack(100);
    struct Node *p;
    int st, f;

    int visited[10];
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
    printf("Enter start vertex: ");
    scanf("%d", &st);
    visited[st] = 1;
    printf("%d ", st);
    push(s, st);
    do
    {
        p = A[st];
        while (p != NULL)
        {
            if (visited[p->vertex] == 0)
            {
                visited[p->vertex] = 1;
                printf("%d ", p->vertex);
                push(s, p->vertex);
                st = p->vertex;
                break;
            }
            else
            {
                p = p->next;
            }
        }
        if (p == NULL)
        {
            f = pop(s);
            if (!isEmpty(s))
            {
                st = s->arr[s->top];
            }
        }
    } while (!isEmpty(s));
}

int main()
{
    struct Node *G[10];
    int v;

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    for (int i = 0; i < v; i++)
    {
        G[i] = NULL;
    }

    AdjList(G, v);
    DFSlist(G, v);

    return 0;
}
