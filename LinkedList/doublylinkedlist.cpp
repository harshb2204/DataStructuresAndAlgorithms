#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

    // Constructor with both data and next parameters
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor with only data parameter, next defaults to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertarrtoDLL(vector<int> &arr){
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for(int i = 1; i< arr.size(); i++){
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;

    }

    return head;

}

void printDLL(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    
}

Node* Deletehead(Node *head){
    if(head==NULL || head->next==NULL){
        return NULL;

    }

    Node *prev = head;
    head=  head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}


Node* deletetail(Node *head){
    if(head==NULL || head->next==NULL){
        return NULL;

    }

    Node*tail = head;


    while(tail->next!=NULL){
        tail = tail->next;
    }

    Node *prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;

}

Node* deletekth(Node *head, int k){
    if(head==NULL){
        return NULL;

    }

    int cnt = 0;
    Node*knode = head;
    while(knode!=NULL){
        cnt++;
        if(cnt==k){
            break;
        }
        knode = knode->next;
}

Node*prev = knode->back;
Node*front = knode->next;

if(prev==NULL && front ==NULL){

    return NULL;

}
else if(prev==NULL){
    return Deletehead(head);
}
else if(front==NULL){
    return deletetail(head);
}
prev->next = front;
front->back = prev;

knode->next = nullptr;
knode->back = nullptr;
delete knode;
return head;


}

void deleteNode(Node*temp){
    Node*prev= temp->back;
    Node*front = temp->next;

    if(front==NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;

    }

    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    free(temp);
}

Node*inserthead(Node*head, int val){
    Node*newhead = new Node(val, head, nullptr);
    head->back = newhead;
    return newhead;
}

Node*insertbeforetail(Node*head, int val){
    if(head->next==NULL){
        return inserthead(head, val);
    }

    Node*tail = head;
    while (tail->next!=NULL){
        tail = tail->next;

    }
    Node*prev = tail->back;
    Node *newnode = new Node(val, tail, prev);
    prev->next = newnode;
    tail->back = newnode;
    return head;

    
}

Node *insertkth(Node *head, int k, int val){
    if(k==1){
        return inserthead(head, val);
    }
    Node*temp = head;
    int cnt = 0;

    while(temp!=NULL){
        cnt++;
        if(cnt == k){
            break;
        }
        temp = temp->next;

        
    }

    Node*prev = temp->back;
    Node *newnode = new Node(val, temp, prev);
    temp->back = newnode;
    prev->next = newnode;
    return head;
}



int main(){

     vector<int> arr = {1,2,3,4,5,6,7,8,9};
    Node* head = convertarrtoDLL(arr);


    head = Deletehead(head);
    printDLL(head);

    


    head= deletetail(head);

    printDLL(head);
    

    head = deletekth(head, 3);
    printDLL(head);

    head = inserthead(head, 14);
    printDLL(head);

    head= insertbeforetail(head, 12);
    printDLL(head);

    head = insertkth(head, 3, 45);
    printDLL(head);




    return 0;



}