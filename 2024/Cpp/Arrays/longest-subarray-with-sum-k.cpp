// subarray means : contigous part of the array
// subsequence : can be non-contigous part of an array 

// Brute force
// Approach: 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> findContiguous(vector<int> &arr, int k) {
    vector<int> res;
    int n = arr.size();
    int start = 0, end = 0, sum = 0;

    while (end < n) {
        sum += arr[end]; // 10
        
        while (sum > k) {   // yes, yes, 10 is greater than 9
            sum -= arr[start]; // remove first element from the sum, sum = 9 
            start++; // start is at 1 now
        }
        
        if (sum == k) { // yes sum is equal now to k
            for (int i = start; i <= end; i++) {
                res.push_back(arr[i]);
            }
            return res;
        } 
        
        end++;
    }
    
    return res;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; 
    int k = 9;
    vector<int> res = findContiguous(arr, k);
    
    cout << "Contiguous elements that sum up to " << k << ": ";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    
    return 0;
}