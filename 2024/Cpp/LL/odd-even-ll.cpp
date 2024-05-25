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
    ListNode* oddEvenList(ListNode* head) {
            if (!head || !head->next) return head;

        ListNode* oddHead = new ListNode(0); // Dummy head for odd list
        ListNode* evenHead = new ListNode(0); // Dummy head for even list
        ListNode* odd = oddHead;
        ListNode* even = evenHead;
        ListNode* current = head;
        int index = 1;

        while (current) {
            if (index % 2 == 1) { // Odd indexed node
                odd->next = current;
                odd = odd->next;
            } else { // Even indexed node
                even->next = current;
                even = even->next;
            }
            current = current->next;
            index++;
        }

        even->next = nullptr; // Terminate the even list
        odd->next = evenHead->next; // Connect odd list to even list

        ListNode* result = oddHead->next; // Result head

        // Clean up dummy nodes
        delete oddHead;
        delete evenHead;

        return result;
    }
};