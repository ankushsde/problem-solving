// Linkedlist ??
//  Why a linkedlist ? what is the need of a linkedlist?
//  In arrays we have stored data at a contigous location, also data is fixed, whether likedlist helps in increasing or decreasing the size.
//  Linkedlists doesn't stores  data in contigous locations(memory)
//  data is stored in a heap memory

// How we store? we store something we call nest, this is the next node/
// starting point of the linkedlist is called as head
// and there is a tail, which is what name justifies, the last node
// used in stack and queue, we can see our browsers are working on this
// we have pointers in linkedlist which points

// we ususally define in struct or class

// Approach 1 : Brute force
// Using a stack , step (1) insert , step (2) pop
// Tc: O(2N), for inserting and poping out the values
// SC: O(N)

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *temp = head; // never temper head
        stack<int> st;         // initializing a stack

        while (temp != nullptr)
        {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head; // reset the temp pointer to the head of the linkedlist

        while (temp != nullptr)
        {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};

// Approach Optimal :
// flip the order of connection, which means we'll change the direction of the arrows, which results in : last will becomes new first element. 
//TC: O(N), SC:O(1)


class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *temp = head;
        ListNode* prev = NULL;

        while (temp != NULL)
        {
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};

// Approach Optmial:
// Using recursive way
// TC: O(N), SC:O(1)

 if (head == NULL || head->next == NULL) {
        return head;
         }
         ListNode* newHead = reverseList(head->next);
         ListNode* front = head->next;
         front->next = head;
         head->next = NULL;
         return newHead;
