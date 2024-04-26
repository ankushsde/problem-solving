class Solution {
public:

int exe(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
if(i>j)
return 0;

if(dp[i][j] != -1)
return dp[i][j];

int res=INT_MIN;
for(int k=i; k<=j; k++){
    int c= nums[i-1]*nums[k]*nums[j+1] + exe(i,k-1,nums,dp)+ exe(k+1,j,nums,dp);
res=max(c,res);
}
return dp[i][j]=res;
}
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return exe(1,n,nums,dp);
    }
};