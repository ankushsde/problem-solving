//Problem statement :
// You must be familiar with the concept of have a pointer attached to a node in linked list,
// In this problem, we are given two pointers, one is the next and another one will be any random pointer attached to any of the node
// and we're supposed to create a deep copy of this linkedlist and return the head from the copied linked list

// don't feel worried it's super simple.

// Brute Force

// Approach: 
// we'll break down this into 3 steps: 
// first : create each and every node of each value (deep copying)
// second : to remember the address of the created node in step 1, we'll use a hashmap
// In hashmap we'll be storing the nodes of orignial and copied linkedlist, remember we're not storing the value in hashmap, we'll be storing the nodes.
// third : make sure that the next pointer and random pointer are pointing to the correct node. 

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp =  head;
        map<Node*,Node*> mpp;
        while(temp!=NULL){
            Node* newNode = new Node(temp->val);
            mpp[temp] = newNode;
            temp= temp->next;
        }
        temp = head;
        while(temp!=NULL){
            Node* copyNode = mpp[temp];
            copyNode->next = mpp[temp->next];
            copyNode->random = mpp[temp->random];
            temp = temp->next;
        }
        return mpp[head];
    }
};

// TC: O(n) + O(n), Once for inserting in the map and other for linking nodes with next and random pointer.
// SC: O(n)

//Better:
   //Better
        Node* temp = head;
        while(temp!=NULL){
             Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }

        temp = head;
        Node* copyNode = new Node(temp->val);
        while(temp != NULL){
            copyNode= temp->next;
            if (temp->random != NULL) 
             copyNode->random = temp->random->next;
             temp = temp->next->next;
        }
        
        temp = head;
        Node* dNode = new Node(-1);
        Node* res = dNode;
        while(temp != NULL){
            res = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp= temp->next;
        }
        return dNode->next;
 


// Better: 
// Approach: We'll be not using hashmap to store the copied node.
// Instead of storing the copied nodes, we can insert the copyNodes in between the list
// Three steps
// frist : Creating a copy and storing them 
// second : connect the random pointer
// third : connect the next pointer
//  TC: O(3N) SC: O(N)(as question demands to return), no extra space used in this approach

//Psuedo code: 
// step 1
 temp = head;
 while(temp != NULL){
    copyNode = new node(temp->val)
    copyNode->next = temp->next
    temp->next = copyNode
    temp = temp->next->next
 }
 //step 2 
  temp = head;
  while(temp != NULL){
    copyNode = temp->next
    copyNode->random = temp->random->next
    temp= temp->next->netx
  }
  //step 3 
  dNode = new Node(-1)
  res = dNode;
  temp = head;
  while(temp != NULL){
    res->next = temp->next
    temp->next = temp->next->next
    res = res->next
    temp = temp->next
  }
