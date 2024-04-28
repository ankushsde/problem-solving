// brute force:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        vector<int> values;
        
        // Push values of nodes into the vector
        while(temp != nullptr){
            values.push_back(temp->val);
            temp = temp->next;
        }
        
        // Sort the vector
        sort(values.begin(), values.end());
        
        // Update the values of the linked list nodes with sorted values
        temp = head;
        for(int i = 0; i < values.size(); ++i){
            temp->val = values[i];
            temp = temp->next;
        }
        
        return head;
    }
};
// TC: o(n) + O(NLOGN)+ O(N)
//SC: O(N)

//Better way 
