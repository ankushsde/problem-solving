class Solution {
public:
int countPartitions(vector<int> &weights, int maxSum) {
    int n = weights.size(); //size of array.
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++) {
        if (subarraySum + weights[i] <= maxSum) {
            //insert element to current subarray
            subarraySum += weights[i];
        }
        else {
            //insert element to next subarray
            partitions++;
            subarraySum = weights[i];
        }
    }
    return partitions;
}

    int shipWithinDays(vector<int>& weights, int days) {
           int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int partitions = countPartitions(weights, mid);
        if (partitions > days) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
    }
};