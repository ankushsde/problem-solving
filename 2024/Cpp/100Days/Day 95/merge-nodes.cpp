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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        while(temp!=NULL)
        {
            ListNode* temp1=temp->next;
            ListNode* currSum=temp1;
            int sum=0;
            while(temp1!=NULL && temp1->val!=0)
            {
                sum+=temp1->val;
                temp1=temp1->next;
            }

            if(currSum!=NULL)
            {
                currSum->val=sum;
                currSum->next=temp1->next;
            }
            temp=temp1;
        }
        return head->next;
    }
};