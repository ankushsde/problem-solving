#include <bits/stdc++.h>
using namespace std;

int largestSub (vector<int> &arr){
 int maxLen = 0;
    int currentSum = 0;
    unordered_map<int, int> lastIndex;   

     lastIndex[0] = -1;

    for (int i = 0; i < arr.size(); i++) {
        currentSum += arr[i];
         if (currentSum % 2 == 0) {
            maxLen = max(maxLen, i + 1);
        }
         else if (lastIndex.find(currentSum % 2) != lastIndex.end()) {
            maxLen = max(maxLen, i - lastIndex[currentSum % 2]);
        }
         else {
            lastIndex[currentSum % 2] = i;
        }
    }

    return maxLen;
};

int main() {
int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        int N;
        cin >> N; // Read the size of the array
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i]; // Read the array elements
        }
        cout << largestSub(arr) << endl;
    }

    return 0;
}
