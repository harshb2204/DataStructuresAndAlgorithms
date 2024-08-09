#include<stdio.h>
struct student{
    int rollno;
    char name[30];
    char address[30];
    int age;


};
void print1(struct student s1[5]){
   printf("Name of students having age 14 are:");
    for(int i=1;i<=5;i++){
        if (s1[i-1].age==14){
            printf("%s\n",s1[i-1].name);
        }
    }

}
void print2(struct student s1[5]){
    printf("Names of students having even roll no:");
    for(int i=1;i<=5;i++){
        if(s1[i-1].rollno%2==0){
            printf("%d\n",s1[i-1].rollno);
        }
    }


}
void print3(struct student s1[5]){
    printf("Enter roll number to search:");
    int x;
    scanf("%d",&x);
    for(int i=1;i<=5;i++){
        if(s1[i-1].rollno==x){
            printf("It is in this list\n");
            printf("%d\n",s1[i-1].rollno);
            printf("%s\n",s1[i-1].name);
            printf("%s\n",s1[i-1].address);
        }
    }
}
int main(){
    struct student s1[5];
    for(int i=1;i<=5;i++){
        printf("Enter roll no. of student %d\n",i);
        scanf("%d",&s1[i-1].rollno);
        printf("Enter the name of student %d\n",i);
        scanf("%s",&s1[i-1].name);
        printf("Enter the address of student %d\n ",i);
        scanf("%s",&s1[i-1].address);
        printf("Enter the age of student %d\n",i);
        scanf("%d",&s1[i-1].age);
    }
    print1(s1);
    print2(s1);
    print3(s1);

}
