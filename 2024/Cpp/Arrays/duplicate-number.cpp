// revisted
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

    
     int n = nums.size();

    //optimal using linkedllist cycle detection method 
        int slow = nums[0];
        int fast = nums[0];
         
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while (slow!=fast);

        fast = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;

      //Brute force
        // sort(nums.begin(),nums.end());
        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         if(nums[i] == nums[j]) {
        //             return nums[i];
        //         }
        //     }
        // }
        
        // return -1; 
     
     //hashing 

     int hash[n+1];
    //   for(int i = 0; i<=n; i++){
    //     hash[i]= 0;
    //   }
    //   for(int i = 0; i<n; i++){
    //     hash[nums[i]]++;
    //     if(hash[nums[i]]>1){
    //         return nums[i];
    //     }
    //   }
    //   return 0;

    }

    vector<int> duplicates(vector<int>& nums) {
      vector<int> ans;
      int n = nums.size();
      
      unordered_map<int, int> hash;
     
      for(int i = 0; i<n; i++){
          hash[nums[i]]++;
          if(hash[nums[i]] > 1 ){
              ans.push_back(nums[i]);
          }
      }
      return ans;
 }
};

// O(n) ::: TC ,,,, O(n) :::: SC