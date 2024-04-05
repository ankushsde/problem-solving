#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    public: 
    
    void subsetSumHelper(int ind, int sum, vector<int> &arr, vector<int> &ans, int n ){
        if(ind == n){
            ans.push_back(sum);
            return;
        }
        //if the element is picked
        subsetSumHelper(ind+1,sum+arr[ind], arr, ans, n);
        //if the element is not picked
        subsetSumHelper(ind+1, sum, arr, ans, n);
    };
    
    vector<int> subsetSums(vector<int> arr, int n){
        vector<int>ans;
        subsetSumHelper(0,0,arr,ans,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    vector<int> arr = {3,1,2};
    Solution ob;
    vector<int> ans = ob.subsetSums(arr,arr.size());
    sort(ans.begin(),ans.end());
    cout<< "the possible subsets are : "<<endl;
    
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<",";
    }

    return 0;
}

//TC: 2^N + 2^Nlog2^N
//SC: O(N)