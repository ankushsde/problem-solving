

// find out the minimum energy required by fron to jump
// We cann go with the greedy way but some of the edge case won't work, enrgy becomes zero, 0
// To do it rcursive way, thing of a problem in this patterns

//1. Try to represent the problem in terms of index
//2. Do all possible stuffs on that index
//3. Dpends on what you want you want to count, just count that, either count max of all stuffs or min. 

f(ind)
{
 if(ind == 0) return 0;

 left = f(ind -1) + abs(a[ind] - a[ind-1]);
 if (ind >1) {
 right = f(ind-2) + abs(a[ind] - a[ind-2]);
 }
 return min(left,right)

}

// using recursion - > DP WAY
#include <bits/stdc++.h> 

int f(int ind, vector<int> &heights, vector<int> &dp){
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];
    int left = f(ind-1,heights, dp) + abs(heights[ind] - heights[ind-1]);
    int right = INT_MAX;
    if(ind>1) right = f(ind -2, heights, dp) + abs(heights[ind] - heights[ind-2]);
    return dp[ind]= min(left,right); 
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return f(n-1, heights, dp);
}

// memoized way - > DP way

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp (n,0);
    dp[0] = 0;
    for(int i = 1; i<n;i++){
     int fs = dp[i-1] + abs(heights[i]-heights[i-1]);
     int ss = INT_MAX;
     if(i>1) ss = dp[i-2] + abs(heights[i] - heights[i-2]);    
     dp[i] = min(fs,ss); 
    }
    return dp[n-1];
}

//uisng Tabulation - Optimized space, playing around the indexes, prev, prev2, and current i

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp (n,0);
    // dp[0] = 0;
    prev = 0;
    prev2 = 0;
    for(int i = 1; i<n;i++){
     int fs = prev + abs(heights[i]-heights[i-1]);
     int ss = INT_MAX;
     if(i>1) ss = prev2 + abs(heights[i] - heights[i-2]);    
     int curi = min(fs,ss);
     prev2 = prev;
     prev = curi; 
    }
    return prev;
}

