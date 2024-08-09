#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int lbit, rbit;
    struct node *left, *right;
};

struct node *createTBT(struct node *head, int key)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key;
    temp->lbit = temp->rbit = 0;

    if (head->lbit == 0)
    {
        head->lbit = 1;
        head->left = temp;
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
        else if (key > p->data && p->rbit)
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
        p->left = temp;
        p->lbit = 1;
    }

    if (key > p->data)
    {
        temp->left = p;
        temp->right = p->right;
        p->right = temp;
        p->rbit = 1;
    }
    return head;
}

void preOrderTBT(struct node *head)
{
    struct node *p = head->left;
    while (p != head)
    {
        printf("%d ", p->data);
        if (p->lbit == 1)
        {
            p = p->left;
        }
        else if (p->rbit == 1)
        {
            p = p->right;
        }
        else if (p->rbit == 0)
        {
            while (p->rbit == 0)
            {
                p = p->right;
            }
            p = p->right;
        }
    }
}

void preOrderTBT2(struct node *head)
{
    struct node *p = head->left;
    while (p != head)
    {
        printf("%d ", p->data);
        if (p->lbit == 1)
        {
            p = p->left;
        }
        else if (p->rbit == 1)
        {
            p = p->right;
        }
        else
        {
            while (p != head && p->rbit == 0)
            {
                p = p->right;
            }
            if (p != head)
            {
                p = p->right;
            }
        }
    }
}

void main()
{

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->rbit = 1;
    head->lbit = 0;
    head->left = head->right = head;
    head = createTBT(head, 1);
    head = createTBT(head, 2);
    head = createTBT(head, 3);
    head = createTBT(head, 4);
    head = createTBT(head, 5);

    preOrderTBT2(head);
}