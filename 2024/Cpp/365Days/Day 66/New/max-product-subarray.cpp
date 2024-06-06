// never confuse when it comes to subarrays, they are contigous
// Brute :Generating all the possible subarrays and finding the max
// this approach will be using 3 nested loops 
// TC: close to O(N^3) and SC: O(1)

int maxProductSubArray(vector<int>& nums) {
    int n  = nums.size();
    int maxi = INT_MIN;
    for(int i = 0; i< n; i++){
        for(int j = i ; j< n; j++){
            int product = 1;
            for(int k = i; k<j; k++){
                product = product * nums[k];
               
            }
            maxi = max(maxi,product);
        }
    }
    return maxi;
}

//Can be trimmed down to N^2, because everytime we're multiplying with new num, and what if we multiply next element with the product 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int n  = nums.size();
    int maxi = INT_MIN;
    for(int i = 0; i< n; i++){
        int product = 1;
        for(int j = i ; j< n; j++){
            product = product * nums[j];
            maxi = max(maxi,product);
        }
    }
    return maxi;
    }

};
// Otimal::::  using prefix and sufix based on intution 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
      int maxi = INT_MIN;
      int pref = 1;
      int suff = 1;
      for(int i = 0; i<n; i++){
        if(pref == 0) pref = 1;
        if(suff == 0) suff = 1;

        pref = pref * nums[i];
        suff = suff * nums[n-i-1];

        maxi = max(maxi, max(pref,suff));
      }
      return maxi;
    }

};