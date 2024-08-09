#include<stdio.h>
#include<stdlib.h>

struct node{
       struct node*prev;
       struct node*next;
       int data;

};



void LinkTraversal(struct node*head){
   struct node*p = head;
   do{

    printf("Element:%d\n",p->data);
    p = p->next;


   }while(p!=head);


}

int main(){
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
    fourth->next = head;

    LinkTraversal(head);



}


