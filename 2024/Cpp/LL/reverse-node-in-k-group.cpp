class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Create a dummy node and point it to the head of the list
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        // Pointer to traverse the list
        ListNode* curr = dummy;
        
        // Loop until curr reaches the end of the list
        while (curr != nullptr) {
            // Detect the length of the current group
            int count = 0;
            ListNode* temp = curr->next;
            while (temp != nullptr && count < k) {
                temp = temp->next;
                count++;
            }
            
            // If the length of the current group is less than k, break the loop
            if (count < k) break;
            
            // Reverse the current group
            ListNode* prev = nullptr;
            ListNode* next = nullptr;
            ListNode* tail = curr->next;
            temp = curr->next;
            for (int i = 0; i < k; ++i) {
                next = temp->next;
                temp->next = prev;
                prev = temp;
                temp = next;
            }
            
            // Connect the reversed group to the previous part of the list
            curr->next = prev;
            // Connect the tail of the reversed group to the next node after the reversed group
            tail->next = temp;
            // Move curr to the next group
            curr = tail;
        }
        
        // Return the modified list
        return dummy->next;
    }
};
