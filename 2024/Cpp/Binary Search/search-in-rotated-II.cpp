class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int n = nums.size();
         int low = 0;
         int high = n-1;

         while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return true;

            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low = low + 1;
                high = high-1;
                continue;
            }


            //check for sorted array 
            if(nums[low]<= nums[mid]){
                //check if target is present or not
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid -1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(nums[high]>=target && target >= nums[mid]){
                    low = mid +1;
                }
                else {
                    high = mid-1;
                }
            }
         }
         return false;
    }
};