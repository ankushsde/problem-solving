// brute force:
// this approach is based on simple sorting using a temp vector;
// step-1 --> push all the tem->value to the temp vector, say values
// step-2 --> Sort teh values vector
// step-3 --> sort
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

//Better way using merge sort;
//TC: o(logN)*(N+N/2) , SC:O(logN)
class Solution {
public:
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    };

    ListNode* mergeTwoList(ListNode* list1, ListNode* list2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if(list1) temp->next = list1;
        else temp->next = list2;
        return dummyNode->next;

    };

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* middle = findMiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = nullptr;
        left = sortList(left);
        right = sortList(right);
        return mergeTwoList(left,right);

    }
};
