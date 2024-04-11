// Intuition
// The problem requires finding the top K frequent elements in an array of integers. One approach is to use a map to count the frequency of each element, then sort the elements based on their frequency and return the top K elements.
// Screenshot (47).png

// Approach
// Initialize an empty map mp to store the frequency of each element.
// Iterate through the input nums array and update the frequency of each element in the map.
// Create a vector of pairs v, where each pair consists of the frequency and the corresponding element.
// Sort the vector v in descending order based on the frequency.
// Iterate through the sorted vector v and insert the elements into the result vector ans until k elements are inserted.
// Return the result vector ans.
// Complexity
// Time complexity :
// Constructing the frequency map: O(n)
// Sorting the vector of pairs: O(n log n)
// Extracting the top K elements: O(k)
// Overall, the time complexity is O(n log n), where n is the size of the input array nums.
// Space complexity :
// Additional space used for the map and the vector of pairs: O(n)
// Space required for the result vector: O(k)
// Overall, the space complexity is O(n).
// Code

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int>ans;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        vector<pair<int,int>>v;
        for(auto it : mp )
            v.push_back(make_pair(it.second,it.first));
        sort(v.rbegin(),v.rend());
        for(int i=0;i<v.size() && k!=0 ;i++)
        {
            ans.push_back(v[i].second);
            k--;
        }       
        return ans; 
    }
};

// priority ques:
class MyComp {
public:
  bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        return a.second > b.second;
  }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyComp> pq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        auto itr = mp.begin();
        for (int i = 0; i < k; i++, itr++) {
            pq.push({itr->first, itr->second});
        }

        for (int i = k; i < mp.size(); i++, itr++) {
            if (itr->second > pq.top().second) {
                pq.pop();
                pq.push({itr->first, itr->second});
            }
        }

        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};