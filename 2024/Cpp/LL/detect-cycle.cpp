// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* temp = head;
        unordered_map<ListNode*,int> nodeMap;
        while(temp != nullptr){
            if(nodeMap.find(temp) != nodeMap.end()){
                return true;
            }
            nodeMap[temp]=1;
            temp=temp->next;
        }
        return false;
    }
};

class Solution {

public:
bool detectCycle(Node* head){
Node* slow = head, *fast = head;

while(fast != NULL && fast->next != NULL){
  slow=slow->next;
  fast = fast->next->next;
  If (fast==slow) return true
} 
}
return false 
}

//BRUTE FORCE: TC: O(N*2*LOGN) SC: O(N)