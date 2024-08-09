#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    struct Node **s;
    int size;
};
struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
} *root = NULL;

void stackCreate(struct stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->s = (struct Node **)malloc(st->size * (sizeof(struct Node *)));
}

void push(struct stack *st, struct Node *x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack overflow");
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

struct Node *pop(struct stack *st)
{
    struct Node *x = NULL;
    if (st->top == -1)
    {
        printf("stack underflow");
    }
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int isEmpty(struct stack *st)
{
    if (st->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void IterativePreorder(struct Node *p)
{
    struct stack st;
    stackCreate(&st, 100);

    while (p || !isEmpty(&st))
    {
        if (p)
        {
            printf("%d ", p->data);
            push(&st, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&st);
            p = p->rchild;
        }
    }
}

void insert(int key)
{
    struct Node *t = root;
    struct Node *r = NULL;
    struct Node *p;
    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    while (t != NULL)
    {
        r = t;
        if (key == t->data)
        {
            return;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

int main()
{

    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);

    printf("\nPreorder Traversal\n");
    IterativePreorder(root);

    return 0;
}
