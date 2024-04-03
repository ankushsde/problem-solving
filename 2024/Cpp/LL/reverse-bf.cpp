#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Node {
    
    public:
    int data;
    Node* next;
    
    public: 
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
     public: 
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2ll (vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover  = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next= temp;
        mover = temp;
    }
    return head;
}

Node* reverseLL (Node* head){
    Node* temp = head;
    stack<int>st;
    while(temp){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp){
        temp->data = st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}
   

int main() {
    vector<int> arr = {2,3,4,8};
    Node* head = convertArr2ll(arr);
    Node* temp = reverseLL(head);
    while (temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
        
    }
    // cout<<head->data;
   
    // cout<<reverseLL(head);
    
    return 0;
}


Node* reverseOp(Node* head){
    if(head == NULL || head->next == NULL ){
        return head;
    }
    
    Node* prev = NULL;
    Node* current = head;
    
    while(current != NULL){
        // Store the next node before changing pointers
        Node* nextNode = current->next;
        
        // Reverse the pointers
        current->next = prev;
        current->back = nextNode; // Update back pointer
        
        // Move pointers forward
        prev = current;
        current = nextNode;
    }
    return prev; // Return the new head
}