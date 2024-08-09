#include <stdio.h>
#include <stdlib.h>

struct TwoStacks
{
    int *arr;
    int size;
    int top1, top2;
};

// Function to create two stacks in an array of given size
struct TwoStacks *createTwoStacks(int n)
{
    struct TwoStacks *ts = (struct TwoStacks *)malloc(sizeof(struct TwoStacks));
    ts->size = n;
    ts->arr = (int *)malloc(n * sizeof(int));
    ts->top1 = n / 2 + 1;
    ts->top2 = n / 2;
    return ts;
}

// Method to push an element x to stack1
void push1(struct TwoStacks *ts, int x)
{
    // There is at least one empty space for new element
    if (ts->top1 > 0)
    {
        ts->top1--;
        ts->arr[ts->top1] = x;
    }
    else
    {
        printf("Stack Overflow By element : %d\n", x);
    }
}

// Method to push an element x to stack2
void push2(struct TwoStacks *ts, int x)
{
    // There is at least one empty space for new element
    if (ts->top2 < ts->size - 1)
    {
        ts->top2++;
        ts->arr[ts->top2] = x;
    }
    else
    {
        printf("Stack Overflow By element : %d\n", x);
    }
}

// Method to pop an element from first stack
int pop1(struct TwoStacks *ts)
{
    if (ts->top1 <= ts->size / 2)
    {
        int x = ts->arr[ts->top1];
        ts->top1++;
        return x;
    }
    else
    {
        printf("Stack UnderFlow\n");
        exit(1);
    }
}

// Method to pop an element from second stack
int pop2(struct TwoStacks *ts)
{
    if (ts->top2 >= ts->size / 2 + 1)
    {
        int x = ts->arr[ts->top2];
        ts->top2--;
        return x;
    }
    else
    {
        printf("Stack UnderFlow\n");
        exit(1);
    }
}

int main()
{
    struct TwoStacks *ts = createTwoStacks(5);
    push1(ts, 5);
    push2(ts, 10);
    push2(ts, 15);
    push1(ts, 11);
    push2(ts, 7);

    printf("Popped element from stack1 is: %d\n", pop1(ts));
    push2(ts, 40);
    printf("Popped element from stack2 is: %d\n", pop2(ts));

    // Clean up
    free(ts->arr);
    free(ts);

    return 0;
}
