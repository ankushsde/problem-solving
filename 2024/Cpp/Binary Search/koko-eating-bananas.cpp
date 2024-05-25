//Problem : koko eats bana, we're given piles where koko

class Solution {
public:

    int findMax (vector<int> &piles) {
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i = 0; i<n ; i++ ){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    };

    int calculateTotalHours(vector<int> &piles , int hourly){
        int totalH = 0;
        int n = piles.size();
        for(int i = 0; i< n; i++){
            totalH += ceil((double)(piles[i])/(double)(hourly));
        }
        return totalH;
    };

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 0;
        int high = findMax(piles);
        while(low<=high){
            int mid = (low+high)/2;
            int totalH = calculateTotalHours(piles,mid);
            if(totalH<=h){
                high = mid -1;
            } else {
                low = mid +1;
            }
        }
        return low;
    }
};

// Time Complexity: O(N * log(max(a[]))), where max(a[]) is the maximum element in the array and N = size of the array.
// Reason: We are applying Binary search for the range [1, max(a[])], and for every value of ‘mid’, we are traversing the entire array inside the function named calculateTotalHours().