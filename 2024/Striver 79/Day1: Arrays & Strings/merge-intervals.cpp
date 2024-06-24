class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;

        if(intervals.size() == 0 ){
            return mergedIntervals;
        }

        sort(intervals.begin(), intervals.end()); 
        // time : O(nlogn)+ O(n)
        // space : O(n * m) + O(n)
        vector<int> tempInterval = intervals[0]; 

        for(auto it : intervals){
            if(it[0]<= tempInterval[1]){
                tempInterval[1] = max(it[1],tempInterval[1]);
            } else {
                mergedIntervals.push_back(tempInterval);
                tempInterval = it;
            }
        }

        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
};