// class Solution {
// public:
//     ListNode* removeNodes(ListNode* head) {
//         ListNode* cur = head;
//         stack<ListNode*> stack;
        
//         while (cur != nullptr) {
//             while (!stack.empty() && stack.top()->val < cur->val) {
//                 stack.pop();
//             }
//             stack.push(cur);
//             cur = cur->next;
//         }
        
//         ListNode* nxt = nullptr;
//         while (!stack.empty()) {
//             cur = stack.top();
//             stack.pop();
//             cur->next = nxt;
//             nxt = cur;
//         }
        
//         return cur;
//     }
// };

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr != nullptr) {
            // ListNode* next = curr->next;
            // curr->next = prev;
            // prev = curr;
            // curr = next;
            swap(curr->next, prev);
            swap(prev, curr);
        }

        ListNode* dummyHead = new ListNode(-1);
        ListNode* tempPrev = dummyHead;
        curr = prev;

        while (curr != nullptr) {
            if (curr->val >= tempPrev->val) {
                tempPrev->next = curr;
                tempPrev = curr;
                curr = curr->next;
            } else {
                curr = curr->next;
            }
        }
        tempPrev->next = nullptr;

        ListNode *newPrev = nullptr, *newCurr = dummyHead->next;
        while (newCurr != nullptr) {
            // ListNode* next = newCurr->next;
            // newCurr->next = newPrev;
            // newPrev = newCurr;
            // newCurr = next;
            swap(newCurr->next, newPrev);
            swap(newPrev, newCurr);
        }

        return newPrev;
    }
};