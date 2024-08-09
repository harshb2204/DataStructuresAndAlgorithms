#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor with both data and next parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data parameter, next defaults to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


Node* convertarrtoLL(vector<int> arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); ++i) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* deletehead(Node* head) {
    if (head == nullptr) return nullptr;

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deletelastele(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head; 
        return nullptr;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    return head;
}

void traverseLL(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int lengthOfLL(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

Node* deletek(Node *head,int k){
    if(head==NULL){
        return head;
    }


    if(k==1){
        Node* temp = head;
    head = head->next;
    delete temp;
    return head;

    }

    int count = 0;
    Node*temp = head;
    Node*prev  = NULL;

    while(temp!=NULL){
        count++;

        if(count==k){
            prev->next = prev->next->next;
            delete temp;
            break;

        }
        prev = temp;
        temp = temp->next;
    }
    return head;

}

Node *inserthead(Node *head, int val){
    Node*temp = new Node(val, head);
    return temp;
}

Node *inserttail(Node *head, int val){
    if(head==NULL){
        return new Node(val);
    }
    Node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    Node *newNode  = new Node(val);
    temp->next = newNode;
    return head;
}


Node *insertk(Node*head, int val, int k){
    if(head==NULL){
        if(k==1){
            return new Node(val);

        }
        else{
            return head;
        }
        
    }
    if(k==1){
        Node*temp = new Node(val, head);
        return temp;

    }

    int count = 0;
    Node*temp = head;
    while(temp!=NULL){
        count++;
        if(count==k-1){
            Node*x = new Node(val, temp->next);
            temp->next = x;
            break;

        }
        temp = temp->next;
    }
    return head;

}

int main() {
    vector<int> arr = {4, 5, 8, 7};
    Node* head = convertarrtoLL(arr);
    
    if (head != nullptr) {
        cout << "Head of the linked list is " << head->data << endl;
    }

    traverseLL(head);

    int l = lengthOfLL(head);
    cout << "Length of LL is " << l << endl;

    head = deletehead(head);
    head = deletelastele(head);

    head = deletek(head, 2);

    head = insertk(head, 100,1);

    traverseLL(head);

    
   

    return 0;
}
