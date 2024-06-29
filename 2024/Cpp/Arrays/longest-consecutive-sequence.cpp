// revisted 

//Brute 
//Doing linearly, checking if the i+1 exists, if yes increment count
//initially the longest is 0 as well as count will be 0
// longest = max(longest,count)
//TC: O(N^2)

class Solution {
public:
    int ls(vector<int>nums, int val){
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == val){
                return true;
            }
        }
        return false;
    }
   int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int count = 1;
            int x = nums[i];
            while (ls(nums, x + 1)) {
                x = x + 1;
                count++;
            }
            longest = max(longest, count);
        }
        return longest;
    }
};

//Better
//Approach : sort and keep a track of lastSmaller along with count and longest
// TC: O(nlogn) + O(n)
// SC: O(1)

class Solution {
public:
     
   int longestConsecutive(vector<int>& nums) {
     sort(nums.begin(),nums.end());
     int cnt = 0;
     int longest = 1;
     int lastSmaller = INT_MIN;

    for(int i = 0; i<nums.size(); i++){
        if(nums[i]-1 == lastSmaller){
            cnt = cnt+1;
            lastSmaller = nums[i];
        }
        else if (nums[i] != lastSmaller){
            cnt = 1;
            lastSmaller = nums[i];
        }
         longest = max(longest,cnt);
    }
   return longest;
   }
};

// Optimal 
// Using set, set will store all the unique elements
class Solution {
public:
     
   int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    int longest = 1;
    unordered_set<int> st;
    for(int i = 0; i<n; i++){
        st.insert(nums[i]);
    }
    for(auto it: st){
        if(st.find(it-1) == st.end()){
            int cnt =1;
            int x = it;
            while(st.find(x+1) != st.end()){
                x = x+1;
                cnt = cnt+1;
            }
            longest = max(longest,cnt);
        }
    }
    return longest;
   }
};