class Solution {
public:

    void subset(int ind, vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int n  ){
        if(ind == n){
            ans.push_back(ds);
            return;
        }
        //not pick case 
        
        subset(ind + 1, ds,nums,ans, n);
        //pick the particular index

        ds.push_back(nums[ind]);
        subset(ind + 1, ds,nums, ans, n);
        ds.pop_back();

    }
   
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        subset(0,ds,nums,ans,n);
        return ans;
    }
};

//dp way 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>> dp(n);
        dp[0]={{},{nums[0]}};
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1];
            for(vector<int> j:dp[i-1]){
                j.push_back(nums[i]);
                dp[i].push_back(j);
            }
        }
        return dp[n-1];
    }
};