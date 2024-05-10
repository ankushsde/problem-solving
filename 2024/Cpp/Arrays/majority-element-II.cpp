// Brute force: 
// approach : pick up all and check using a loop
// for each unique element, we'll run another loop and count it's occurence in the given array
// If any element occurs more than the floor of (N/3), we will include it in our answer. 

//TC: O(N^2), SC: O(2), nearby O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls;
        for(int i = 0; i<n; i++){
            if(ls.size() == 0 || ls[0]!=nums[i]){
                int cnt = 0; 
                for(int j = 0; j<n;j++){
                    if(nums[j] == nums[i]){
                        cnt++;
                    }
                }
                if(cnt>(n/3))
                ls.push_back(nums[i]);
            }
            if(ls.size() == 2) break;

        }
        return ls;
        
    }
};

//Better
//approach: using hashing, this will take extra space
// use a hashmap and store the elements as <key, value> pairs.
// check the map if the value for any element is greater than the floor of N/3. 
// TC:O(n * logn) ,insertion in map takes logn time, and doing for n elements
// SC: O(n)
 vector<int> ls;
 map<int,int> mpp;
        int mini = int(n/3)+1;
        for(int i = 0; i<n;i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]] == mini){
                ls.push_back(nums[i]);
            }
            if (ls.size() == 2) break;
        }
        return ls;

//Optimal 
// approach: based on moore's voting algo
// TC:O(N) + O(n),second one is only for cheking purpose , SC: O(1)
   int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;

         for(int i = 0; i< nums.size(); i++){
            if(cnt1 == 0 && nums[i] != el2){
                cnt1 = 1;
                el1 = nums[i];
            }
            else  if(cnt2 == 0 && nums[i] != el1 ){
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(nums[i] == el1){
                cnt1++;
            }
             else if(nums[i] == el2){
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        };
        cnt1 = 0;
        cnt2 = 0;
         for(int i = 0; i< nums.size(); i++){
            if(nums[i] == el1) cnt1++;
            if(nums[i] == el2) cnt2++;

        }
       int mini = int(n / 3) + 1;
       if (cnt1 >= mini) ls.push_back(el1);
       if (cnt2 >= mini) ls.push_back(el2);

    return ls;
