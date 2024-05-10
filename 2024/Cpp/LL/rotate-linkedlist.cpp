// Brute Force
// approach : pick up the last node, put it in the front for k no. of times
//TC: O(k*N) , for every n-time going to find the last node 
// for every k-time going to find last node and put in the front

// Better
// approach : Calculate the length of the list.
// Connect the last node to the first node, converting it to a circular linked list.
// Iterate to cut the link of the last node and start a node of k%length of the list rotated list.
// TC: o(n)+ O(n-(n%k)) , close to O(n), no extra space used O(1)
 ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        ListNode* cur = head;
        int len = 1;
        while(cur->next && ++len)
            cur = cur->next;

        cur->next = head;
        k = k % len;
        k = len - k;
        while(k--) cur = cur->next;

        head = cur-> next;
        cur->next = NULL;

        return head;


