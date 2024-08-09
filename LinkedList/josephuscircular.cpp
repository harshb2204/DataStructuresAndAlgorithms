#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void createCircularList(Node*& head, int n) {
    Node* temp;
    Node* last;

    
    head = new Node();
    head->data = 1;
    head->next = head;
    last = head;

    
    for (int i = 2; i <= n; i++) {
        temp = new Node();
        temp->data = i;
        temp->next = head;
        last->next = temp;
        last = temp;
    }
}

void josephusCircularList(Node*& head, int k) {
    Node* ptr1 = head;
    Node* ptr2 = head;

    while (ptr2->next != head) {
        ptr2 = ptr2->next;
    }

    while (ptr1->next != ptr1) {
        for (int count = 1; count < k; count++) {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }

        ptr2->next = ptr1->next;
        
        delete ptr1;
        ptr1 = ptr2->next;
    }

    cout <<ptr1->data << endl;
}

int main() {
    int n = 7; 
    int k = 3; 

    Node* head = nullptr;

    
    createCircularList(head, n);

    josephusCircularList(head, k);

    return 0;
}
