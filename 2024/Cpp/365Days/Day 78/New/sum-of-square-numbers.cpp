class Solution {
public:
    bool judgeSquareSum(int c) {
         long long left = 0;
        long long right = sqrt(c);
        while (left <= right) {
            long long currentSum = left * left + right * right;
            if (currentSum == c) {
                return true;
            } else if (currentSum < c) {
                ++left;
            } else {
                --right;
            }
        }
        return false;
    }
};