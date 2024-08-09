#include <stdio.h>

void insert(int n, int key, int hashTable[][3])
{
    int i = 0, j, index;
    index = key % n;
    while (hashTable[index][2] && i < n)
    {
        if (hashTable[index][0] % n == key % n)
        {
            break;
        }
        i++;
        index = (index + 1) % n;
    }
    if (i == n)
    {
        printf("Hash table is full\n");
        return;
    }
    while (hashTable[index][1] != -1)
    {
        index = hashTable[index][1];
    }
    j = index;
    while (hashTable[j][2] && j < n)
    {
        j = (j + 1) % n;
        i++;
    }
    if (i == n)
    {
        printf("Hash table is full\n");
        return;
    }
    hashTable[j][0] = key;
    hashTable[j][2] = 1;
    if (j != index)
    {
        hashTable[index][1] = j;
    }
}
void display(int n, int hashTable[][3])
{
    printf("\nHash table : \n");
    printf("\nIndex\tKey\tChain\n");
    for (int i = 0; i < n; i++)
    {
        if (hashTable[i][2])
        {
            printf("%d|\t%d\t%d\n", i, hashTable[i][0], hashTable[i][1]);
        }
        else
        {
            printf("%d|\t-\t%d\n", i, hashTable[i][1]);
        }
    }
}
void main()
{
    int n, nk;
    printf("Enter hash table size : ");
    scanf("%d", &n);
    int hashTable[n][3];

    for (int i = 0; i < n; i++)
    {
        hashTable[i][1] = -1;
        hashTable[i][2] = 0;
    }
    printf("Enter number of keys you want to enter : ");
    scanf("%d", &nk);
    printf("\n");
    for (int i = 0; i < nk; i++)
    {
        int a;
        printf("Enter key : ");
        scanf("%d", &a);
        insert(n, a, hashTable);
    }
    display(n, hashTable);
}
