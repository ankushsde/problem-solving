#include <iostream>
#include <vector>
using namespace std;

vector<int> findContiguous(vector<int> &arr, int k) {
    vector<int> res;
    int n = arr.size();
    int start = 0, end = 0, sum = 0;

    while (end < n) {
        sum += arr[end];
        
        while (sum > k) {
            sum -= arr[start];
            start++;
        }
        
        if (sum == k) {
            for (int i = start; i <= end; i++) {
                res.push_back(arr[i]);
            }
            return res;
        }
        
        end++;
    }
    
    return res;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; 
    int k = 9;
    vector<int> res = findContiguous(arr, k);
    
    cout << "Contiguous elements that sum up to " << k << ": ";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    
    return 0;
}
