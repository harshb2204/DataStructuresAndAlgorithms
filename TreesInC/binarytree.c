//binary tree
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
} *root = NULL;

struct stack
{
    int top;
    struct Node **s;
    int size;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is Full");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node *dequeue(struct Queue *q)
{
    struct Node *x = NULL;
    if (q->front == q->rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmptyQ(struct Queue q)
{
    return q.front == q.rear;
}

void stackCreate(struct stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->s = (struct Node **)malloc(st->size * sizeof(struct Node *));
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
        printf("Stack underflow");
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
    return st->top == -1;
}

void LevelOrder(struct Node *root)
{
    struct Queue q;
    create(&q, 100);

    printf("%d ", root->data);
    enqueue(&q, root);

    while (!isEmptyQ(q))
    {
        root = dequeue(&q);
        if (root->lchild)
        {
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if (root->rchild)
        {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

int Height(struct Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
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

void IterativeInorder(struct Node *p)
{
    struct stack st;
    stackCreate(&st, 100);

    while (p || !isEmpty(&st))
    {
        if (p)
        {
            push(&st, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&st);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

void postOrderTrav(struct Node *curr)
{
    struct stack s1, s2;
    stackCreate(&s1, 100);
    stackCreate(&s2, 100);

    if (curr == NULL)
        return;

    push(&s1, curr);
    while (!isEmpty(&s1))
    {
        curr = pop(&s1);
        push(&s2, curr);
        if (curr->lchild != NULL)
            push(&s1, curr->lchild);
        if (curr->rchild != NULL)
            push(&s1, curr->rchild);
    }
    while (!isEmpty(&s2))
    {
        printf("%d ", pop(&s2)->data);
    }
}

struct Node *InPre(struct Node *p)
{
    while (p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

struct Node *InSucc(struct Node *p)
{
    while (p && p->lchild != NULL)
        p = p->lchild;
    return p;
}

struct Node *Mirror(struct Node *root)
{
    struct Node *temp = root;
    struct stack st;
    stackCreate(&st, 100);
    push(&st, root);

    while (!isEmpty(&st))
    {
        temp = pop(&st);
        struct Node *curr = temp->rchild;
        temp->rchild = temp->lchild;
        temp->lchild = curr;

        if (temp->rchild != NULL)
        {
            push(&st, temp->rchild);
        }
        if (temp->lchild != NULL)
        {
            push(&st, temp->lchild);
        }
    }
    return root;
}

void leafnodes(struct Node *root)
{
    struct stack stk;
    stackCreate(&stk, 100);
    push(&stk, root);
    while (!isEmpty(&stk))
    {
        root = pop(&stk);
        if (root->lchild == NULL && root->rchild == NULL)
        {
            printf("%d ", root->data);
        }
        if (root->rchild != NULL)
        {
            push(&stk, root->rchild);
        }
        if (root->lchild != NULL)
        {
            push(&stk, root->lchild);
        }
    }
}

// Function to create a new Node
struct Node *createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->lchild = NULL;
    n->rchild = NULL;
    return n;
}

int main()
{
    // Manually creating the binary tree
    root = createNode(2);
    root->lchild = createNode(1);
    root->rchild = createNode(4);
    root->rchild->lchild = createNode(3);
    root->rchild->rchild = createNode(5);

    printf("Post Order Traversal\n");
    postOrderTrav(root);

    printf("\nInorder traversal\n");
    IterativeInorder(root);

    printf("\nPreorder Traversal\n");
    IterativePreorder(root);

    printf("\nHeight of the tree: %d\n", Height(root));

    printf("\nLevel Order Traversal\n");
    LevelOrder(root);

    printf("\n\nMirror of the binary tree\n");
    struct Node *mirrored_root = Mirror(root);
    LevelOrder(mirrored_root);

    printf("\n\nLeaf Nodes: ");
    leafnodes(root);
}