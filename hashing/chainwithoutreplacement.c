//chainwithoutreplacement
#include <stdio.h>
#define size 10

void insert(int data[], int chain[], int flag[], int x)
{
    int start;
    int i = 0;
    int j;
    start = x % size;

    while (flag[start] == 1 && i < size) // check if data is there in start index
    {
        if (data[start] % size == x % size)
        {
            break;
        }
        i++;
        start = (start + 1) % size;
    }

    if (i == size)
    {
        printf("Hash table is full\n");
        return; // Add return to stop execution if the hash table is full
    }

    while (chain[start] != -1)
    {
        start = chain[start];
    }

    j = start;
    while (flag[j] && i < size)
    {
        j = (j + 1) % size;
        i = i + 1;
    }

    if (i == size)
    {
        printf("Hash table is full\n");
        return; // Add return to stop execution if the hash table is full
    }

    data[j] = x;
    flag[j] = 1;
    if (j != start)
    {
        chain[start] = j;
    }
}

void display(int data[], int chain[], int flag[])
{
    printf("Index\tData\tChain\tFlag\n");
    for (int i = 0; i < size; i++)
    {
        if (flag[i])
        {
            printf("%d\t%d\t%d\t%d\n", i, data[i], chain[i], flag[i]);
        }
        else
        {
            printf("%d\t-\t-\t%d\n", i, flag[i]);
        }
    }
}

int main()
{
    int data[size], chain[size], flag[size], n, x;

    for (int i = 0; i < size; i++)
    {
        data[i] = -1; // Initialize data array
        chain[i] = -1;
        flag[i] = 0;
    }

    printf("Enter number of keys to be inserted: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter key: ");
        scanf("%d", &x);
        insert(data, chain, flag, x);
    }

    printf("Hash table:\n");
    display(data, chain, flag);

    return 0;
}
