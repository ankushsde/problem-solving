// leetcode 75 question 2
// brute force::
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        for(int i = 0; i< n; i++){
            if(nums[i]!=0){
                temp.push_back(nums[i]);
            }
        }
        for(int i=0; i<temp.size(); i++){
            nums[i]= temp[i];
        }
        int nz = temp.size();
        for(int i = nz; i<n; i++ ){
            nums[i] = 0;
        }
    }

};

// TC: O(n) + O(x) + O(n-x) ,close to O(2n), SC: O(x); 

