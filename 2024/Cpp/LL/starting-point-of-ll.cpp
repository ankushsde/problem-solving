/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         if(head == NULL && head->next == NULL){
            return NULL;
        } 
         ListNode* slow = head; 
         ListNode* fast = head;
         ListNode* entry = head;

         while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast-> next->next;
            if(slow == fast){
                while(slow!=entry){
                    slow = slow->next;
                    entry= entry->next;
                }
                return entry;
            }
         }
         return nullptr; 

        //Better
        
        //approach: using slow and fast pointers
        //we'll detect using two steps:
        //In first step we'll be finding the collision point, using slow and fast pointers moving simultaneously
        //and when they collide, we'll move to our second step which is to find out the starting point of the cycle, 
        //We'll use another pointer named entry, and we'll run slow and entry pointers simultaneously and when they collide, 
        //we get the entry point, unless, there's no cycle

        //edge cases: head is null or head->next is null;
       

        //Brute Force 
        //approach: using a hashtable, before hashing check if node exists previously
        //TC: O(n) SC: O(n)--for hashing all the nodes.
        // ListNode* temp = head;
        // unordered_map<ListNode*,int> mp;

        // while(temp!= NULL){
        //     //detection of the node encountered again
        //  if(mp.count(temp)!=0){
        //     return temp;
        //  }   
        //  mp[temp] = 1;
        //  temp = temp->next;
        // }
        // return nullptr;
    }
};