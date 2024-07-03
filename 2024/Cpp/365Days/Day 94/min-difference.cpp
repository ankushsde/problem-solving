// Using multiset 
class Solution {
public:
    int minDifference(vector<int>& nums) {
         multiset<int> minSet, maxSet;

         for(int num : nums){
            minSet.insert(num);
            
            if(minSet.size() > 4){
                minSet.erase(--minSet.end());
            }

            maxSet.insert(num);

            if(maxSet.size() > 4){
                maxSet.erase(maxSet.begin());
            }
         }

         int minDiff = INT_MAX;

         for(auto it1 = minSet.begin(), it2 = maxSet.begin(); it1 != minSet.end(); it1++, it2++){
            minDiff = min(minDiff,*it2 - *it1);
         }
         
         return minDiff;
    }
};

// TC : O(nlog4) == O(n)
// SC : O(1)

