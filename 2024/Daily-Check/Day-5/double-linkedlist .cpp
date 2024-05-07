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
    ListNode* doubleIt(ListNode* head) {
        ListNode* reversedList = reverseList(head);
        int carry = 0; 
        ListNode* current = reversedList, *previous = nullptr;
        while(current!=nullptr){
            int newValue = current->val * 2 + carry;
            current->val = newValue % 10;
            if(newValue > 9){
                carry = 1;
            } else {
                carry = 0;
            }
            previous = current;
            current = current-> next;
        }
        if(carry!=0){
            ListNode* extraNode = new ListNode(carry);
            previous->next = extraNode;
        }
        ListNode* result = reverseList(reversedList);
        return result;
    }

    ListNode* reverseList(ListNode* head){
       
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* prev = NULL;
    ListNode* current = head;
    while (current != NULL) {
        ListNode* nextTemp = current->next;
        current->next = prev;
        prev = current;
        current = nextTemp;
    }
    return prev;

    }
};


// TC: O(n) & SC: O(n)