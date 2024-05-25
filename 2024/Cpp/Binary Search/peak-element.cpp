// using binary search 
// peak element used to be greater than previous and next, or greater than its neighbours, right? 
// and there are some condtions as we know the elements will be in between -infinity to -infinity
// if(n==1) return 0; // case where we have one element, itself is a peak
// if(arr[0]>arr[1]) return 1; // case where first element is at the peak
// if(arr[n-1] >arr[n-2] ) return n-1; // case where last element is at the peak
// // Binary search why?
// // peak might fall on the left of the mid or right of the mid, or it could be mid
// // binary searching will takes place in between low = 1, high = n-2;
// while(low<=high){
// 	int mid = (low+high)/2;
// 	if( arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
// 	else if(arr[mid] > arr[mid-1]) low = mid+1;
// 		esle high = mid-1;
// }
// TC: O(logN), SC:O(1);

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();  

    // Edge cases:
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else high = mid - 1;
    }
     return -1;
    }
};