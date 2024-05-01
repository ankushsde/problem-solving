//naive approach : Quadratic:
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         vector<int> result;
        int n = nums.size();

        for (int i = 0; i <= n - k; ++i) {  
            int maxi = nums[i];  

            
            for (int j = i + 1 ; j < i + k; ++j) {
                maxi = max(maxi, nums[j]);
            }

            result.push_back(maxi);  
        }

        return result;
    }
};

//Optimal

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>v;
        deque<int>dq;
        for(int i=0; i<nums.size(); i++){
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();

            dq.push_back(i);
            if(i>=k-1) v.push_back(nums[dq.front()]);
        }

        return v;
    }
};

