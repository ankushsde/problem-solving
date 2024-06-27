// Aggresive cows
// brute is to simply check all the distances, and we can find out the limit by sorting the stalls and then, limit = stalls[n-1] - stalls[0]

// then we cheked, dude can we place the cows or not for every distance in that limit depnding on the distance, stalls ans yes surely th ecows count… 

bool canWePlace(vector<int> &stalls, int dist, int cows){
int n = stalls.size();
int cntCows = 1;
int last = stalls[0];

for(int i = 1; i< n ; i++){
 if(stalls[i] - last >= dist){
  cntCows++;
  last = stalls[i];
}
if(cntCows>=cows) return true;
}
return false;
}

int aggresiveCows (vector<int> stalls, int k ){
sort(stalls.begin(),stalls.end());
int limit = stalls[n-1] - stalls[0];

for(int i = 1; i< limit; i++){
if(canWePlace(stalls, i, k)== false){
 return (i-1);
}
}
}

TC: O(max-min) * O(n);
SC: O(1);





// Optimal approach is to do it by using binary search::::

int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); //size of array
    //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}
// Time Complexity: O(NlogN) + O(N * log(max(stalls[])-min(stalls[]))),
 // Reason: O(NlogN) for sorting the array. We are applying binary search on [1, max(stalls[])-min(stalls[])]. 
//  Inside the loop, we are calling canWePlace() function for each distance, ‘mid’. 
// Now, inside the canWePlace() function, we are using a loop that runs for N times.

