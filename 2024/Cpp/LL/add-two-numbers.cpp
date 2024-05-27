
// Approch, using basic math where we'll be taking care of carry
// TC: Max of (n1,n2), because we're going to travere the largest ofthe linkedlist 
// SC: O(max of (n1,n2))

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry) {
            int sum = 0; 
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 !=NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
};

// psuedo code: 
// we'll be using a dummy node and will be connecting the result to this node
// see the numbers can be from 0..9, means we've to take care of carry,
// initialize carry and sum variable to store the result as 0, for every iteration the sum will become zero. 
// loop untill we have elements present in list1 or list list 2 or we have a carry
// check if(list1 !=NULL){
// //add list1->value to sum;
// // keep it moving // list1 = list1->next 
// }
// same for list 2, 

// add carry in ths sum, if it is 
// sum += carry;
// carry = sum/10;
// we'll need a new node, which we'll assigning to node next, 
// node = new Node (sum%10);
// temp->next = node;
// temp = temp->next;

// Return dummynode ->next
