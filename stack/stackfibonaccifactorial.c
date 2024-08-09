#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    int *s;
};

void create(struct stack *st)
{
    printf("Enter size of the stack\n");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}

void display(struct stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        printf("%d\n", st.s[i]);
    }
}

void push(struct stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int factorial(int n)
{
    struct stack st;
    st.size = n;
    st.top = -1;
    st.s = (int *)malloc(st.size * sizeof(int));

    while (n > 1)
    {
        push(&st, n);
        n--;
    }

    int result = 1;
    while (st.top != -1)
    {
        result *= pop(&st);
    }

    free(st.s);
    return result;
}

void fibonacci(int n)
{
    struct stack st;
    st.size = n;
    st.top = -1;
    st.s = (int *)malloc(st.size * sizeof(int));

    if (n > 0)
        push(&st, 0); // F(0)
    if (n > 1)
        push(&st, 1); // F(1)

    for (int i = 2; i < n; i++)
    {
        int b = pop(&st);
        int a = pop(&st);
        push(&st, a);     // push back a
        push(&st, b);     // push back b
        push(&st, a + b); // push F(i)
    }

    printf("Fibonacci series up to %d terms:\n", n);
    display(st);

    free(st.s);
}

int main()
{
    struct stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);

    printf("Before pop operation\n");
    display(st);

    printf("After pop operation\n");
    pop(&st);
    display(st);

    int num;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);
    printf("Factorial of %d is %d\n", num, factorial(num));

    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &num);
    fibonacci(num);

    return 0;
}
