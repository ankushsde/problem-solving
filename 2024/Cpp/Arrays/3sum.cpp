// Brute force 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
 
         set <vector<int>> st;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j<n; j++){
                for(int k = j+1 ; k<n; k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                        vector<int>temp = {nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};

//Better - n^2
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
 
        set<vector<int>> st;
        for(int i = 0; i < n - 2; i++) {
            set<int> hashSet;  
            for(int j = i+1; j < n; j++) {
                int third = -(nums[i] + nums[j]);
                if (hashSet.find(third) != hashSet.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};


// using 2pointers 

