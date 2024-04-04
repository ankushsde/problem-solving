 #include <iostream>
#include <bits/stdc++.h>
#include <algorithm> 
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    public: 
    Node (int data1, Node* next1){
        data = data1;
        next = next1;
    }
    
    public: 
    Node (int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL (vector<int> &arr){
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* mover =  head;
    
    for(int i = 1; i< arr.size(); i++ ){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
    
};

Node* getNode(Node* head , int val){
    while(head->data != val ) head = head->next;
    return head;
}
void deleteNode(Node* t) {
    t->data = t->next->data;
    t->next = t->next->next;
    return;
}
 
int main() {
    vector<int> list1 = {1,2,4,7};
    
    Node* head = convertArr2LL(list1);
    Node* t = getNode(head,4);
    deleteNode(t);
    Node* temp = head;
     while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
     
    return 0;
}