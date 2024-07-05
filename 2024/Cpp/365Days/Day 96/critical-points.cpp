// Brute force 
// TC:O(N) , SC: O(N)
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if( !head || !head->next || !head->next->next){
            return {-1,-1};
            // No enough nodes to have critical points
        }
        ListNode* temp = head;
        int key = 1;
        map<ListNode*, int> mpp;
           // populate the map with nodes and their corresponding keys
        while(temp!= nullptr){
            mpp[temp] = key;
            key++;
            temp = temp->next;
        }
        
        vector<int> criticalPoints;
        temp = head->next;
        
        ListNode* prevNode = head;
        ListNode* currNode = temp;
        ListNode* nextNode = temp->next;

        while(nextNode != nullptr){
            
            if( currNode->val > prevNode->val && currNode->val > nextNode->val && 
                currNode->val < prevNode->val && currNode->val < nextNode->val){
                criticalPoints.push_back(mpp[currNode]);
            }
            prevNode = currNode;
            currNode = nextNode; 
            nextNode = nextNode->next;   
        }

        // edge case where we have not enough points to calculate the distances
        if(criticalPoints.size() < 2){
            return {-1,-1};
        }

        int minDistance = INT_MAX;
        int maxDistance = criticalPoints.back() - criticalPoints.front();
         
        for(int i = 0; i< criticalPoints.size(); ++i){
            minDistance = min(minDistance, criticalPoints[i]-criticalPoints[i-1]);
        }

        return {minDistance, maxDistance};
    }
};

// Better
// TC: O(n) / SC: O(1)
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if( !head || !head->next || !head->next->next){
            return {-1,-1};
            // No enough nodes to have critical points
        }
        ListNode* temp = head;        
        vector<int> criticalPoints;
        temp = head->next;
        
        ListNode* prevNode = head;
        ListNode* currNode = temp;
        ListNode* nextNode = temp->next;

        while(nextNode != nullptr){
            
            if( currNode->val > prevNode->val && currNode->val > nextNode->val || 
                currNode->val < prevNode->val && currNode->val < nextNode->val){
                criticalPoints.push_back(mpp[currNode]);
            }
            prevNode = currNode;
            currNode = nextNode; 
            nextNode = nextNode->next;   
        }

        // edge case where we have not enough points to calculate the distances
        if(criticalPoints.size() < 2){
            return {-1,-1};
        }

        int minDistance = INT_MAX;
        int maxDistance = criticalPoints.back() - criticalPoints.front();
         
        for(int i = 1; i< criticalPoints.size(); ++i){
            minDistance = min(minDistance, criticalPoints[i]-criticalPoints[i-1]);
        }

        return {minDistance, maxDistance};
    }
};