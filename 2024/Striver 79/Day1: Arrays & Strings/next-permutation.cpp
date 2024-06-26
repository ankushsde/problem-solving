// generating all the permutations using recursion 
void recPermute (vector<int> &ds,vector<int> &nums,vector<vector<int>> &ans, int freq[]  ){
    if(ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }
    for(int i = 0; i< nums.size(); i++){
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i] = 1;
            recPermute(ds,nums,ans,freq);
            freq[i]= 0;
            ds.pop_back();
        }
    }
    
} 

vector<vector<int>> permutations(vector<int> arr){
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[arr.size()];
    for(int i = 0 ; i< arr.size(); i++) freq[i] = 0;
    recPermute(ds,arr,ans,freq);
    return ans;
  }

// TC: O(n! * n) && SC: O(n) + O(n) + O(n) ds, map, and auxialary space stack 
void recPermute (int index, vector<int> &nums,vector<vector<int>> &ans  ){
    if(index == nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i = index; i< nums.size(); i++){
         swap(nums[index], nums[i]);
         recPermute(index+1, nums, ans);
         swap(nums[index], nums[i]);
    }
    
} 

vector<vector<int>> permutations(vector<int> arr){
    vector<vector<int>> ans;
    recPermute(0,arr,ans);
    return ans;
  }

  // This above approach results in better space complexity which is o(n) which is the recursion dpeth, but by using these brute forces
//    the time complexity still remains the same 

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int ind = -1;
        int n = nums.size();
        // find the break point, the longer prefix match 
        for(int i = n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }

        // edge case 
        if(ind == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        // step 2 , find the smallest one, so that we can stay close to next permutation
        for(int i = n-1; i>=0; i--){
            if (nums[i] > nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }

        // reverse , try to place remaining in the sorted order
        reverse(nums.begin() + ind+1, nums.end());

    }
};

// TC: O(3N) 
//modifying the arr sc: 0(1) 
