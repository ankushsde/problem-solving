int maxProduct(vector<int> &nums){
    int n = nums.size();
    int res = 0; 
    int cur_max = nums[0];

    for(int i = 0; i< n; i++){
        res = max(res, (cur_max -1)*(nums[j] -1));
        cur_max = max(cur_max, nums[j]);
    }
    return res;
    
}

// TC: O(N)
// SC: O(1)