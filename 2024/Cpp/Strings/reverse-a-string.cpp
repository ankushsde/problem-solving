class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s, 0, s.size() - 1);
    }

private:
    void reverse(vector<char>& s, int left, int right) {
        if (left >= right) return;
        swap(s[left], s[right]);
        reverse(s, left + 1, right - 1);
    }
};

//

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};