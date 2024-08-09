//chainwithreplacement
#include <stdio.h>
#define size 10

void insert(int data[], int chain[], int flag[], int x)
{
    int start;
    int i = 0;
    int j;
    start = x % size;

    // Find the position for new element or replacement
    while (flag[start] == 1 && i < size) 
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
        return;
    }

    // If the position is occupied, we need to do chaining with replacement
    if (flag[start] == 1)
    {
        int prev_index = -1;
        int curr_index = start;
        while (curr_index != -1)
        {
            if (data[curr_index] % size == x % size)
            {
                prev_index = curr_index;
            }
            curr_index = chain[curr_index];
        }

        if (prev_index != -1)
        {
            j = start;
            while (flag[j] && i < size)
            {
                j = (j + 1) % size;
                i = i + 1;
            }

            if (i == size)
            {
                printf("Hash table is full\n");
                return;
            }

            data[j] = x;
            flag[j] = 1;
            if (j != start)
            {
                chain[start] = j;
            }
        }
        else
        {
            // Find new position to insert the new element
            j = start;
            while (flag[j] && i < size)
            {
                j = (j + 1) % size;
                i = i + 1;
            }

            if (i == size)
            {
                printf("Hash table is full\n");
                return;
            }

            // Place the new element at the position found
            data[j] = x;
            flag[j] = 1;

            // Replace the old element and update the chain
            int old_value = data[start];
            data[start] = x;
            flag[start] = 1;

            // Rehash the old value
            insert(data, chain, flag, old_value);
        }
    }
    else
    {
        data[start] = x;
        flag[start] = 1;
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
        data[i] = -1;
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
