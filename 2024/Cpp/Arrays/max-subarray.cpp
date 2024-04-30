// Brute Force 

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;

            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}
// TC: N^3

// Better - N^2

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;

            sum += arr[j];

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

//Kadane's Algorithm 
// O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum = 0 , maxi = LONG_MIN;
        for(int i = 0 ; i< nums.size() ; i++){
            sum += nums[i];
            if(sum>maxi){
                maxi = sum;
            }
            if(sum<0){
                sum = 0;
            }
        }
        return maxi;
    }
};

// Follow up - akka genius level 

#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; 
    long long sum = 0;
    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {
        if(sum == 0 ) start = i;
        sum += arr[i];
         if(sum>maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum<0){
            sum = 0;
        }
        maxi = max(sum,maxi);

 }
  for(int i = ansStart; i<ansEnd; i++){
     cout<<arr[i]<<" ";
 }
 return maxi;
}

int main()
{
    int arr[] = { -2, -3,4,-1,-2,1,5,-3};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}


