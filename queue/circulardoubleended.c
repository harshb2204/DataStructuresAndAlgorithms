//circdequeue
#include <stdio.h>
#include <stdlib.h>

struct circQue {
    int f;
    int r;
    int size;
    int *arr;
};

int isFull(struct circQue *q) {
    return (q->r + 1) % q->size == q->f;
}

int isEmpty(struct circQue *q) {
    return q->f == -1;
}

void enqueue(struct circQue *q, int val) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }

    if (isEmpty(q)) {
        q->f = q->r = 0;
    } else {
        q->r = (q->r + 1) % q->size;
    }

    q->arr[q->r] = val;
}

void deque(struct circQue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    int val = q->arr[q->f];
    if (q->f == q->r) {
        q->f = q->r = -1;
    } else {
        q->f = (q->f + 1) % q->size;
    }

    printf("dequed: %d\n", val);
}

void addfront(struct circQue *q, int val) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }

    if (isEmpty(q)) {
        q->f = q->r = 0;
    } else {
        q->f = (q->f - 1 + q->size) % q->size;
    }

    q->arr[q->f] = val;
}

void removeRear(struct circQue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    int val = q->arr[q->r];
    if (q->f == q->r) {
        q->f = q->r = -1;
    } else {
        q->r = (q->r - 1 + q->size) % q->size;
    }

    printf("removed from rear: %d\n", val);
}

void printQueue(struct circQue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    int i = q->f;
    while (i != q->r) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("%d\n", q->arr[i]);  
}

int main() {
    struct circQue *que = (struct circQue *)malloc(sizeof(struct circQue));
    que->f = -1;
    que->r = -1;
    que->size = 10;
    que->arr = (int *)malloc(que->size * sizeof(int));

    enqueue(que, 10);
    enqueue(que, 20);
    enqueue(que, 30);
    printQueue(que);  
    addfront(que, 5);
    printQueue(que);  
    deque(que);
    printQueue(que);  
    deque(que);
    printQueue(que);  
    removeRear(que);
    printQueue(que);  
    removeRear(que);
    printQueue(que);  

    free(que->arr);
    free(que);

    return 0;
}