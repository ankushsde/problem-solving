class Solution {
public:
    // Static comparison function
    static bool comparet(const string &x, const string &y) {
        return x + y > y + x;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> s;
        
        // Convert each integer to a string
        for (int i = 0; i < nums.size(); i++) {
            s.push_back(to_string(nums[i]));
        }
        
        // Sort the strings based on custom comparator
        sort(s.begin(), s.end(), Solution::comparet);
        
        // Build the result string
        string ans = "";
        for (const auto &c : s) {
            ans += c;
        }

        // Edge case: If the result starts with '0', it means all numbers were zero
        if (ans[0] == '0') {
            return "0";
        }

        return ans;
    }
};