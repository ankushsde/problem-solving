//revisted 22May
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    public: 
    vector <vector<string>> partions(string s){
       vector<vector<string>> res;
        vector<string> path;
        partitionHelper(0,s,path,res);
        return res;
    }
    void partitionHelper(int index, string s, vector < string > & path,
    vector < vector < string > > & res) {
    if (index == s.size()) {
      res.push_back(path);
      return;
    }
    for (int i = index; i < s.size(); ++i) {
      if (isPalindrome(s, index, i)) {
        path.push_back(s.substr(index, i - index + 1));
        partitionHelper(i + 1, s, path, res);
        path.pop_back();
      }
    }
  }

  bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
};

int main() {
    string s = "aabb";
    Solution obj;
    vector<vector<string>> ans = obj.partions(s);
    int n = ans.size();
  cout << "The Palindromic partitions are :-" << endl;
  cout << " [ ";
  for (auto i: ans) {
    cout << "[ ";
    for (auto j: i) {
      cout << j << " ";
    }
    cout << "] ";
  }
  cout << "]";
    

    return 0;
}