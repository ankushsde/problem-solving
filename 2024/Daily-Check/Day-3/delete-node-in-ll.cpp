// simply pointing the node next value to the node val;
// and node->next to node-> next -> next 

node->val = node->next->val;
node->next = node->next->next;