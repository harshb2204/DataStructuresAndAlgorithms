//heapsort

#include <stdio.h>
#include <string.h>

struct Student
{
    int rollNumber;
    float cgpa;
    char name[50];
};

void Insert(struct Student A[], int n)
{
    int i = n;
    struct Student temp;
    temp = A[i];
    while (i > 1 && temp.rollNumber > A[i / 2].rollNumber)
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

struct Student Delete(struct Student A[], int n)
{
    int i, j;
    struct Student x, temp, val;
    val = A[1];

    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = i * 2;
    while (j <= n - 1)
    {
        if (j < n - 1 && A[j + 1].rollNumber > A[j].rollNumber)
            j = j + 1;
        if (A[i].rollNumber < A[j].rollNumber)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    return val;
}

int main()
{
    struct Student A[] = {
        {0, 0.0, ""},
        {14, 9.1, "J"},
        {15, 7.6, "A"},
        {5, 9.6, "B"},
        {20, 7.9, "E"},
        {30, 6.7, "C"},
        {8, 8.6, "D"},
        {40, 7.4, "F"}};

    int n = sizeof(A) / sizeof(A[0]) - 1;

    int i;
    for (i = 2; i <= n; i++)
        Insert(A, i);

    for (i = n; i > 1; i--)
        Delete(A, i);

    for (int i = 1; i <= n; i++)
        printf("Roll: %d, CGPA: %.2f, Name: %s\n", A[i].rollNumber, A[i].cgpa, A[i].name);
    printf("\n");

    return 0;
}
