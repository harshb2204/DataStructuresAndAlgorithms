#include <stdio.h>

struct employee {
 char name[100];
 int age;
 float salary;
 char department[50];
};

int main(){
   struct employee employeeone, *ptr;

   printf("Enter Name, Age, Salary and Department of Employee\n");
   scanf("%s %d %f %s", &employeeone.name, &employeeone.age,
       &employeeone.salary, &employeeone.department);



   ptr = &employeeone;
   printf("\nEmployee Details\n");
   printf(" Name : %s\n Age : %d\n Salary = %f\n Dept : %s\n",
       ptr->name, ptr->age, ptr->salary, ptr->department);

   return 0;
}
