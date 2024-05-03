// We can solve this problem two ways, let's do it first with brute force

//Brute force 
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
 
int main() {
 
    vector<int> arr = {};
    vector<int> list1 = {1,2,4};
    vector<int> list2 = {1,3,4};
    Node* head1 = convertArr2LL(list1);
    Node* head2 = convertArr2LL(list2);
    Node* temp1 = head1;
    Node* temp2 = head2;
    
    while(temp1){
        arr.push_back(temp1->data);
        // cout<< temp1->data<<" ";
        temp1 = temp1->next; 
    }
    temp2 = head2; 
    while(temp2){
        arr.push_back(temp2->data);
        temp2 = temp2->next;
    }
    
    sort(arr.begin(),arr.end());
    
    Node* head = convertArr2LL(arr);
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
     
    return 0;
}

// TC: O(N1)+O(N2)+O(NlogN)+O(N)
// SC: O(N)+O(N)

//Optimal 

int main() {
    vector<int> list1 = {1,2,4};
    vector<int> list2 = {1,3,4};
    
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    
    Node* head1 = convertArr2LL(list1);
    Node* head2 = convertArr2LL(list2);
    Node* t1 = head1;
    Node* t2 = head2;
    
    while(t1 != NULL && t2!=NULL){
        if(t1->data < t2->data){
            temp->next = t1;
            temp=t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            temp=t2;
            t2=t2->next;
        }
    }
    if(t1) temp->next = t1;
    else temp->next = t2;
    
    temp = dummyNode->next;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
     
    return 0;
}

// TC:O(N1+N2) SC:O(1)