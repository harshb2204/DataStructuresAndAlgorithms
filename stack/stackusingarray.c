#include <stdio.h>
#include <stdlib.h>

struct stack{
    int top;
    int size;
    int *s;
};

void create(struct stack *st){
    printf("Enter size of the stack\n");
    scanf("%d", &st->size);
    st->top =-1;
    st->s = (int*)malloc(st->size*sizeof(int));



}

void display(struct stack st){

    int i;
    for(int i = st.top; i>=0;i--){
        printf("%d\n ", st.s[i]);
    }
}

void push(struct stack  *st, int x){
    
    if(st->top==st->size-1){
        printf("stack overflow");
    }
    else{
        st->top++;
        st->s[st->top]=x;
    }


}

int pop(struct stack *st){
    int x = -1;
    if(st->top==-1){
        printf("stack underflow");

    }
    else{
        x = st->s[st->top];
        st->top--;

    }
    return x;
}

int main(){

    struct stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);

    printf("Before pop operation\n");

    display(st);

    printf("after pop operation\n");

    pop(&st);
    display(st);
    return 0;

}