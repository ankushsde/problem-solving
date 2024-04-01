class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        for(int i = 0; i<=n; i++){
            ans = ans ^ i;
        }
        for(int i = 0; i<n;i++){
            ans = ans ^ nums[i];
        }
        return ans;


        // int missing = -1;
        // for(int i = 0; i<=n; i++){
        //      int count = 0;
        //      for(int j = 0; j<n;j++){
        //         if(nums[j]==i) count++;
        //      }
        //        if(count== 0 ) missing = i;
        // }
        // return missing;

    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        for(int i = 0; i<=n; i++){
            ans = ans ^ i;
        }
        for(int i = 0; i<n;i++){
            ans = ans ^ nums[i];
        }
        return ans;


        // int missing = -1;
        // for(int i = 0; i<=n; i++){
        //      int count = 0;
        //      for(int j = 0; j<n;j++){
        //         if(nums[j]==i) count++;
        //      }
        //        if(count== 0 ) missing = i;
        // }
        // return missing;

    }
};

