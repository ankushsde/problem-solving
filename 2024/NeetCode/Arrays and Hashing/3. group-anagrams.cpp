// using hashing and sorting 
class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        vector<string> sortedStrings;
        int n = strs.size();

        for(int i = 0; i<n; i++ ){
            string curr = strs[i];
            sort(curr.begin(),curr.end());
            sortedStrings.push_back(curr);
        }

        unordered_map<string,vector<string>> mapped;
        for(int i =0; i< n; i++){
            string currSorted = sortedStrings[i];
            string orgStr = strs[i];
            mapped[currSorted].push_back(orgStr);
        }
        for( auto kv : mapped){
            anagrams.push_back(kv.second);
        }
        return anagrams;
    }
};

// TC: O(n* nlogn) :