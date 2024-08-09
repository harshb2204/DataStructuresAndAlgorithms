//bst
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
struct Node *Delete(struct Node *p, int key)
{
    struct Node *q;

    if (p == NULL)
        return NULL;
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if (key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if (key > p->data)
        p->rchild = Delete(p->rchild, key);
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
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
int countNodesIterative(struct Node *root)
{
    if (root == NULL)
        return 0;

    struct Queue q;
    create(&q, 100);
    enqueue(&q, root);

    int count = 0;
    while (!isEmptyQ(q))
    {
        struct Node *current = dequeue(&q);
        count++;

        if (current->lchild != NULL)
            enqueue(&q, current->lchild);
        if (current->rchild != NULL)
            enqueue(&q, current->rchild);
    }

    return count;
}
int heightNonRecursive(struct Node *root)
{
    if (root == NULL)
        return 0;

    struct Queue q;
    create(&q, 100);
    enqueue(&q, root);

    int height = 0;
    while (!isEmptyQ(q))
    {
        int nodeCount = q.rear - q.front; // Number of nodes at current level
        height++;

        // Dequeue all nodes of current level and enqueue all nodes of next level
        while (nodeCount > 0)
        {
            struct Node *current = dequeue(&q);
            if (current->lchild != NULL)
                enqueue(&q, current->lchild);
            if (current->rchild != NULL)
                enqueue(&q, current->rchild);
            nodeCount--;
        }
    }

    return height;
}

int main()
{

    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);

    printf("Post Order Traversal\n");
    postOrderTrav(root);

    printf("\nInorder traversal\n");
    IterativeInorder(root);

    printf("\nPreorder Traversal\n");
    IterativePreorder(root);

    printf("\nHeight of the tree: %d\n", Height(root));

    printf("\nHeight of the tree: non recursive %d\n", heightNonRecursive(root));

    printf("\nLevel Order Traversal\n");
    LevelOrder(root);

    printf("\nNumber of nodes in the tree: %d\n", countNodesIterative(root));

    printf("\n\nMirror of the binary tree\n");
    struct Node *mirrored_root = Mirror(root);
    LevelOrder(mirrored_root);

    printf("\n\nLeaf Nodes: ");
    leafnodes(root);

    int key_to_delete = 20;
    root = Delete(root, key_to_delete);
    printf("\n\nAfter deleting %d, Inorder traversal\n", key_to_delete);
    IterativeInorder(root);

    printf("\nHeight of the tree after deletion: %d\n", Height(root));

    return 0;
}
