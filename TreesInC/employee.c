//employeebst
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int emp_id;
    char name[100];
    int age;
    struct Employee *lchild;
    struct Employee *rchild;
};

// Function to create a new employee node
struct Employee* createEmployee(int emp_id, char name[], int age) {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
    newEmployee->emp_id = emp_id;
    strcpy(newEmployee->name, name);
    newEmployee->age = age;
    newEmployee->lchild = newEmployee->rchild = NULL;
    return newEmployee;
}

// Function to insert a new employee record into the BST
struct Employee* insertEmployee(struct Employee* root, int emp_id, char name[], int age) {
    if (root == NULL) {
        return createEmployee(emp_id, name, age);
    }

    if (emp_id < root->emp_id) {
        root->lchild = insertEmployee(root->lchild, emp_id, name, age);
    } else if (emp_id > root->emp_id) {
        root->rchild = insertEmployee(root->rchild, emp_id, name, age);
    }

    return root;
}

// Function to search for an employee by emp_id
struct Employee* searchEmployee(struct Employee* root, int emp_id) {
    if (root == NULL || root->emp_id == emp_id) {
        return root;
    }

    if (emp_id < root->emp_id) {
        return searchEmployee(root->lchild, emp_id);
    } else {
        return searchEmployee(root->rchild, emp_id);
    }
}

// Function to perform an in-order traversal of the BST
void inorderTraversal(struct Employee* root) {
    if (root != NULL) {
        inorderTraversal(root->lchild);
        printf("Emp ID: %d, Name: %s, Age: %d\n", root->emp_id, root->name, root->age);
        inorderTraversal(root->rchild);
    }
}

int main() {
    struct Employee* root = NULL;

    // Insert employee records
    root = insertEmployee(root, 102, "Alice", 30);
    root = insertEmployee(root, 101, "Bob", 25);
    root = insertEmployee(root, 104, "Charlie", 28);
    root = insertEmployee(root, 103, "David", 35);

    // Search for an employee by ID
    int search_id = 104;
    struct Employee* searchedEmployee = searchEmployee(root, search_id);
    if (searchedEmployee != NULL) {
        printf("Employee found: Emp ID: %d, Name: %s, Age: %d\n", searchedEmployee->emp_id, searchedEmployee->name, searchedEmployee->age);
    } else {
        printf("Employee with ID %d not found.\n", search_id);
    }

    // Sort and display employee records by emp_id
    printf("\nEmployee records sorted by Emp ID:\n");
    inorderTraversal(root);

    return 0;
}
