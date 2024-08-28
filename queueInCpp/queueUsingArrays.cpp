#include<bits/stdc++.h>

using namespace std;

class Queue {
    int *arr;
    int front, rear, currSize, queueSize;
public:
    Queue() {
        arr = new int[16];
        front = -1;
        rear = -1;
        currSize = 0;
        queueSize = 16;
    }

    Queue(int queueSize) {
        this->queueSize = queueSize;
        arr = new int[queueSize];
        front = -1;
        rear = -1;
        currSize = 0;
    }

    void enqueue(int newElement) {
        if (currSize == queueSize) {
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }
        if (rear == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % queueSize;
        }
        arr[rear] = newElement;
        cout << "The element enqueued is " << newElement << endl;
        currSize++;
    }

    int dequeue() {
        if (front == -1) {
            cout << "Queue Empty\nExiting..." << endl;
            exit(1);
        }
        int dequeued = arr[front];
        if (currSize == 1) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % queueSize;
        }
        currSize--;
        return dequeued;
    }

    int top() {
        if (front == -1) {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[front];
    }

    int size() {
        return currSize;
    }
};

int main() {
    Queue q(6);
    q.enqueue(4);
    q.enqueue(14);
    q.enqueue(24);
    q.enqueue(34);
    cout << "The front of the queue before deleting any element is " << q.top() << endl;
    cout << "The size of the queue before deletion is " << q.size() << endl;
    cout << "The first element to be dequeued is " << q.dequeue() << endl;
    cout << "The front of the queue after deleting an element is " << q.top() << endl;
    cout << "The size of the queue after deleting an element is " << q.size() << endl;

    return 0;
}
