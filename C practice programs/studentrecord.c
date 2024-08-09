#include<stdio.h>
#include<string.h>
struct student
{
    int rollno;
    char name[50];
};
int main()
{
    int i;
    struct student st[2];
    printf("Enter details of students \n");
    for(i=0;i<2;i++)
    {
        printf("enter roll number:");
        scanf("%d",&st[i].rollno);
        printf("enter name:");
        scanf("%s",&st[i].name);
    }
    printf("\n student info is :");
     for(i=0;i<2;i++)
     {
        printf("\n roll no: %d , name: %s",st[i].rollno,st[i].name);
     }
     return 0;
}
