class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;
        unordered_map<string, int> mp;

        string word;

        stringstream ss1(s1);
        while(ss1 >> word){
            mp[word]++;
        }
        stringstream ss2(s2);
        while(ss2 >> word){
            mp[word]++;
        }

        for (auto pair : mp){
            if(pair.second == 1){
                res.push_back(pair.first);
            }
        }
        return res;
    }
};