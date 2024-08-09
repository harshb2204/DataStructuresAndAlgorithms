//quick sort

#include <stdio.h>
#include <stdlib.h>

struct student
{
    int rollno;
    char name[20];
    float CGPA;
};

void swap(struct student *a, struct student *b)
{
    struct student temp = *a;
    *a = *b;
    *b = temp;
}

int partition(struct student arr[], int l, int h)
{
    int pivot = arr[l].rollno;
    int i = l, j = h + 1;

    do
    {
        do
        {
            i++;
        } while (arr[i].rollno <= pivot);

        do
        {
            j--;
        } while (arr[j].rollno > pivot);

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    } while (i < j);

    swap(&arr[l], &arr[j]);
    return j;
}

void quickSort(struct student arr[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(arr, l, h);
        quickSort(arr, l, j);
        quickSort(arr, j + 1, h);
    }
}

int main()
{
    struct student students[] =
        {
            {78, "Harsh", 8.77},
            {31, "hello", 9.0},
            {76, "random", 7.1},

        };

    int n = 3;

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("NAME: %s, Roll no: %d, CGPA: %.2f\n", students[i].name, students[i].rollno, students[i].CGPA);
    }

    quickSort(students, 0, n - 1);

    printf("After sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("NAME: %s, Roll no: %d, CGPA: %.2f\n", students[i].name, students[i].rollno, students[i].CGPA);
    }

    return 0;
}
