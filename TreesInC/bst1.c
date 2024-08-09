#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} *root = NULL;

struct stack
{
    int top;
    int size;
    struct Node **S;
};

void createstack(struct stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size * (sizeof(struct Node *)));
}

void push(struct stack *st, struct Node *x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack is full");
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

struct Node *pop(struct stack *st)
{
    struct Node *x = NULL;
    if (st->top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        x = st->S[st->top];
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

void createbst(int data)
{
    struct Node *p;
    struct Node *r = NULL;
    struct Node *t = root;
    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->left = p->right = NULL;
        root = p;
        p->data = data;
        return;
    }

    while (t != NULL)
    {
        r = t;
        if (data < t->data)
        {
            t = t->left;
        }
        else if (data > t->data)
        {
            t = t->right;
        }
        else
        {
            return;
        }
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->left = p->right = NULL;
    p->data = data;
    if (data < r->data)
    {
        r->left = p;
    }
    else
    {
        r->right = p;
    }
}

void Preorder(struct Node *p)
{
    struct stack st;
    createstack(&st, 100);
    while (p || !isEmpty(&st))
    {
        if (p)
        {
            printf("%d\n", p->data);
            push(&st, p);
            p = p->left;
        }
        else
        {
            p = pop(&st);
            p = p->right;
        }
    }
}

int main()
{

    createbst(15);
    createbst(20);
    createbst(62);
    createbst(42);
    createbst(21);
    Preorder(root);
}
