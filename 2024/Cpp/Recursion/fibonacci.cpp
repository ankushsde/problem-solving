//  dp way, coversion of recursion to dp : 
// TC: O(n)
// SC: O(n)+ O(n), for recursion stack space and array 
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int f(int n, vector<int> &dp){
    if(n<=1) return n ; 
    
    if(dp[n] != -1) return dp[n];
    return dp[n] = f(n-1,dp)+ f(n-2,dp); 
}

int main() {
     int n ;
     cin>> n; 
     vector<int> dp(n+1,-1);
     cout<<f(n, dp);

    return 0;
}

// Memoized 
// TC: O(n)
// SC: O(n)

int main() {
     int n ;
     cin>> n; 
     vector<int> dp(n+1);
     dp[0]= 0;
     dp[1] = 1; 
    
     for(int i = 2; i<= n; i++){
         dp[i]= dp[i-1]+dp[i-2];
         
     }
     int res = dp[n];
    cout << res << endl;
     
    return 0;
}

// tabulation 
//TC: O(n), SC: O(1)
int main() {
     int n ;
     cin>> n; 
     vector<int> dp(n+1);
     int prev2= 0;
     int prev = 1; 
    
     for(int i = 2; i<= n; i++){
         int curri= prev+prev2;
         prev2 = prev;
         prev = curri;
         
     }
     cout << prev << endl;
     
    return 0;
}