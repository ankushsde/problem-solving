class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nextGreaterArr;
        
        for(int i = 0; i < nums1.size(); i++) {
            int nextGreater = -1;
            bool found = false;
            for(int j = 0; j < nums2.size(); j++) {
                if(nums2[j] == nums1[i]) {
                    found = true;
                }
                if(found && nums2[j] > nums1[i]) {
                    nextGreater = nums2[j];
                    break;
                }
            }8
            nextGreaterArr.push_back(nextGreater);
        }
        
        return nextGreaterArr;
    }
};

// optimal using stack 


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res(nums1.size() , -1); // result array
        stack<int>stk; // stack
        map<int,int>mp; // hash map
        for(int num : nums2){

            // stack.top < num
            while(!stk.empty() and stk.top() < num){
                mp[stk.top()] = num;
                stk.pop();
            }
            // push into stack
            stk.push(num);
        }
        for(int i = 0 ; i < nums1.size() ; i++){
            if(mp[nums1[i]]) 
                res[i] = mp[nums1[i]];
        }
        return res;
    }
};

// O(N) &&&&& O(N)