// brute froce 
#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN;
    vector<int> maxSubarray;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            vector<int> tempSubarray;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
                tempSubarray.push_back(arr[k]);
            }
            if (sum > maxi) {
                maxi = sum;
                maxSubarray = tempSubarray;
            }
        }
    }

    return {maxi, maxSubarray};
}

int main() {
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    auto result = maxSubarraySum(arr, n);
    int maxSum = result.first;
    vector<int> maxSubarray = result.second;

    cout << "The maximum subarray sum is: " << maxSum << endl;
    cout << "The subarray with the largest sum is: ";
    for (int i = 0; i < maxSubarray.size(); i++) {
        cout << maxSubarray[i] << " ";
    }
    cout << endl;

    return 0;
}

// TC: O(n^3) ans Sc for printing the subarray O(n)

// Kadane's ALgo 
long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}



// folow up 

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}