// brute force using a stack , which leads to space complexity of O(N) AND TC: O(N)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;

        // Push all elements of the linked list to the stack
        while(temp != nullptr ){
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        // Compare elements from the linked list and stack
        while(temp != nullptr){
            if(temp->val != st.top()){
                return false;
            }
            st.pop(); // Pop the top element from the stack
            temp = temp->next; // Move to the next node in the linked list
        }
        return true;
    }
};
