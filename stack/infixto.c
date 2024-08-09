#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("StackOverflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int space(char c) {
    return c == ' ' || c == '\t';
}

int precedence(char symbol) {
    if (symbol == '^') {
        return 3;
    } else if (symbol == '*' || symbol == '/') {
        return 2;
    } else if (symbol == '+' || symbol == '-') {
        return 1;
    } else {
        return 0;
    }
}

void inToPost() {
    int i, j = 0;
    char next;
    char symbol;
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        if (!space(symbol)) {
            if (symbol == '(') {
                push(symbol);
            } else if (symbol == ')') {
                while ((next = pop()) != '(') {
                    postfix[j++] = next;
                }
            } else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^') {
                while (!isEmpty() && precedence(stack[top]) >= precedence(symbol)) {
                    postfix[j++] = pop();
                }
                push(symbol);
            } else {
                postfix[j++] = symbol;
            }
        }
    }
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void print() {
    printf("%s\n", postfix);
}

int main() {
    scanf("%s", infix);
    inToPost();
    print();
    return 0;
}
