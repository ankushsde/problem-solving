//1
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int ans = 0;
      unordered_map<int, int> ump;
      for(auto h: hours){
        ans += ump[(24 - h%24)%24];
        ump[h%24]++;
    }
    return ans;
    }
};

//2
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
    long long ans = 0;
    unordered_map<int, int> ump;
    for(auto h: hours){
        ans += ump[(24 - h%24)%24];
        ump[h%24]++;
    }
    return ans;
}
};