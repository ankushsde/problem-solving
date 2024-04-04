// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Write C++ code here
    int v = 49;
    vector<int> ans;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;
    for(int i = n-1; i>=0; i--){
        while (v>=coins[i]){
            v -= coins[i];
            ans.push_back(coins[i]);
        }
    }
    cout<<ans.size()<<endl;
    cout<<"coins";
    for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }


    return 0;
}