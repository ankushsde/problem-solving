// Problem 
// Trapping Rainwater
//explanation:
//we need to find the amount of water can be stored at a partiocular index, we got hights of the bar.. 

//Brute Force
//Approach: see, we have multiple bars and to store water, we need two bars, both left and right, what if we find
// the maximum bar at leftmost and rightmost, and then finding the minimum of both and subtract the current index value, We can do it. 

// CPP CODE:
class Solution {
public:
    int trap(vector<int>& heights) {
     int res = 0;
     int n = heights.size();
     for(int i = 0; i<n ; i++){
        int j = i;
        int leftMax = 0;
        int rightMax = 0;
        while(j>=0){
            leftMax = max(leftMax,heights[j]);
            j--;
        }
        j=i;
        while(j<n){
            rightMax = max(rightMax, heights[j]);
            j++;
        }
        res+= min(leftMax,rightMax) - heights[i];
     }
     return res;
    }
};

//TC: O(N^2);
//SC: O(1);

// Better Approach 
// Approach: we can think of using prefix and suffix, prefix.. By using this we removed the nested loop, 
// where we're traversing for entire left and entire right to individually find out the left max and right max,
//TC:  O(3n) close to O(n), calculate for prefix O(n) + for suffix O(n) + for traversing all to execute O(n)
//SC:O(2N) , O(N)+O(N) for prefix and suffix arrays.
class Solution {
public:
    int trap(vector<int>& arr) {
    int n  = arr.size();
      int prefix[n], suffix[n];
      prefix[0] = arr[0];
      for(int i =1; i<n; i++){
        prefix[i] = max(prefix[i-1],arr[i]);
      };
      suffix[n-1] = arr[n-1];
      for(int i = n-2; i>=0; i--){
        suffix[i] = max(suffix[i+1],arr[i]);
      };

      int res = 0;
      for(int i = 0; i<n; i++){
        res += min(prefix[i], suffix[i]) - arr[i]; 
      }
      return res;
    }
};

// Optimal, why? Space complexity 
// Approach:  Using two pointers 
// TC:O(n) , SC:O(1)

class Solution {
public:
    int trap(vector<int>& height) {
    int n  = height.size();
    int left = 0;
    int right = n-1;
    int res = 0;
    int maxLeft = 0; 
    int maxRight = 0;

    while(left <= right){
        if(height[left] <= height[right]){
            if(height[left] >= maxLeft){
                maxLeft = height[left];
            } else{
                res += maxLeft - height[left];
            }
            left++;
        } 
        else{
            if(height[right] >= maxRight){
                maxRight = height[right];
            }else{
                res += maxRight - height[right];
            }
            right--;
        }
    }
    return res;
    }
};