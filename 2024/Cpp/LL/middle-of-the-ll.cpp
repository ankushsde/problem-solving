
//revisited once 
while(fast!=NULL&& fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
}