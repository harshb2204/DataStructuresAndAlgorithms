//tbt
#include <stdio.h>
#include <stdlib.h>

struct TBTNode
{
    int data;
    int lbit;
    int rbit;
    struct TBTNode *left;
    struct TBTNode *right;
};

struct TBTNode *createTBT(struct TBTNode *head, int key)
{
    struct TBTNode *temp, *p;
    temp = (struct TBTNode *)malloc(sizeof(struct TBTNode));
    temp->data = key;
    temp->lbit = temp->rbit = 0;

    if (head->lbit == 0)
    {
        head->left = temp;
        head->lbit = 1;
        temp->left = temp->right = head;
        return head;
    }
    p = head->left;
    while (1)
    {
        if (key < p->data && p->lbit == 1)
        {
            p = p->left;
        }
        else if (key > p->data && p->rbit == 1)
        {
            p = p->right;
        }
        else
        {
            break;
        }
    }

    if (key < p->data)
    {
        temp->right = p;
        temp->left = p->left;
        p->lbit = 1;
        p->left = temp;
    }
    if (key > p->data)
    {
        temp->right = p->right;
        temp->left = p;
        p->rbit = 1;
        p->right = temp;
    }
    return head;
}

void preorder(struct TBTNode *head)
{
    struct TBTNode *p;
    p = head->left;
    while (p != head)
    {
        printf("%d ", p->data);
        if (p->lbit == 1)
        {
            p = p->left;
        }
        else
        {
            while (p->rbit == 0 && p->right != head)
                p = p->right;
            p = p->right;
        }
    }
}

struct TBTNode *findParent(struct TBTNode *p)
{
    struct TBTNode *child = p;
    // ancestor of child
    while (p->rbit == 1)
        p = p->right;
    p = p->right;

    if (p->left == child)
        return p;

    p = p->left;
    while (p->right != child)
    {
        p = p->right;
    }
    return p;
}

struct TBTNode *postSuccessor(struct TBTNode *p)
{
    struct TBTNode *cur = p;
    struct TBTNode *parent = findParent(cur);

    if (parent->right == cur)
        return parent;
    else
    {
        while (p->rbit == 1)
            p = p->right;
        p = p->right;

        if (p->rbit == 1)
        {
            p = p->right;
            while (!(p->rbit == 0 && p->lbit == 0))
            {
                if (p->lbit == 1)
                    p = p->left;
                else if (p->rbit == 1)
                    p = p->right;
            }
        }
    }
    return p;
}

void postorder(struct TBTNode *head)
{
    struct TBTNode *p = head->left;
    struct TBTNode *temp = p;
    while (!(p->rbit == 0 && p->lbit == 0))
    {
        if (p->lbit == 1)
        {
            p = p->left;
        }
        else if (p->rbit == 1)
            p = p->right;
    }
    printf("%d ", p->data);

    while (p != head->left)
    {
        p = postSuccessor(p);
        printf("%d ", p->data);
    }
}
void inOrderTBT(struct TBTNode *head)
{
    struct TBTNode *p = head->left;

    while (p->lbit != 0)
    {
        p = p->left;
    }
    while (p != head)
    {
        printf("%d ", p->data);

        if (p->rbit == 1)
        {
            p = p->right;
            while (p->lbit != 0)
            {
                p = p->left;
            }
        }
        else if (p->rbit == 0)
        {
            p = p->right;
        }
    }
}

int main()
{
    int n;
    int key;

    struct TBTNode *head;
    head = (struct TBTNode *)malloc(sizeof(struct TBTNode));
    head->rbit = 1;
    head->lbit = 0;
    head->left = head->right = head;
    head = createTBT(head, 17);
    head = createTBT(head, 2);
    head = createTBT(head, 34);
    head = createTBT(head, 4);
    head = createTBT(head, 5);

    printf("Preorder: ");
    preorder(head);
    printf("\nPostorder: ");
    postorder(head);
    printf("Inorder");
    inOrderTBT(head);
    return 0;
}
