// Three approaches:
// 1. Using nested loops, we can find out if there are any duplicates
// 2. Using sorting, sort the array and then check if the neighboring element is similar or not, 
// you can also check for the prev or next: 
// 3. using a hashset or hashtable , we'll store all the unique values in the set and we can compare it with the original size 
// of the array.. this will cause us extra space but can offer better time complexity.. 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int i = 0; i<nums.size();i++){
            set.insert(nums[i]);
        }
        if(set.size() != nums.size()) return true;
        return false;
    }
};

