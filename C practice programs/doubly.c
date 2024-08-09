
#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node* prev;
    struct node* next;
    int data;
};

void LinkTraversal(struct node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node* insertatbeg(struct node* head, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

struct node*insertinbet(struct node*head,int index,int data){
struct node*ptr = (struct node*)malloc(sizeof(struct node));
struct node *p = head;
ptr->data = data;
struct node*temp = (struct node*)malloc(sizeof(struct node));
for(int i =0;i<index;i++){
    p=p->next;
}
temp = p->next;
p->next = ptr;
temp->prev = ptr;
ptr->next = temp;
ptr->prev = p;
return head;



}

int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));

    head->prev = NULL;
    head->data = 6;
    head->next = second;

    second->prev = head;
    second->data = 7;
    second->next = third;

    third->prev = second;
    third->data = 8;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 7;
    fourth->next = NULL;

    printf("Before insertion:\n");
    LinkTraversal(head);

    //head = insertatbeg(head, 56);

    printf("After insertion:\n");
    //LinkTraversal(head);

    head = insertinbet(head,2,89);
    LinkTraversal(head);

    return 0;
}
