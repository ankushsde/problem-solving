// dp - memoization
class Solution {
public:

    int f(int ind, vector<int> &nums, vector<int> &dp){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;
        if( dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + f(ind-2, nums, dp);
        int notPick = 0 + f(ind-1, nums, dp);
        return dp[ind] = max(pick,notPick); 
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums,dp);
    }
};

// tabulation 
class Solution {
public:

    int f(int n, vector<int> &nums, vector<int> &dp){
         dp[0] = nums[0];
         
        for(int i = 1; i< n; i++){
            int pick = nums[i];
            if(i>1){
                pick += dp[i-2];
            }
            int notPick = 0 + dp[i-1];
            dp[i] = max(pick,notPick);
        }

        return dp[n-1]; 
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        return f(n,nums,dp);
    }
};

// space optimized in dp-tabulation
class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0; 

        for(int i = 0; i< n ; i++){
            int take = nums[i];
            if(i >1){
                take += prev2;
            }
            int notTake = 0 + prev;
            int curi = max(take,notTake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};
