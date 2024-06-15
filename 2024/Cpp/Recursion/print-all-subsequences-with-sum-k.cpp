#include <iostream>
#include <vector>
using namespace std;

void printF(int ind, int s, vector<int> &ds, int arr[], int n, int sum){
    // Base case: if we have reached the end of the array
    if(ind == n){
        // If the current sum matches the desired sum, print the subsequence
        if(s == sum){
            for(auto it : ds){
                cout << it << " ";
            }
            cout << endl;
        }
        return; 
    }
   
    // Include the current element in the subsequence
    ds.push_back(arr[ind]);
    s += arr[ind];
    printF(ind + 1, s, ds, arr, n, sum);

    // Exclude the current element from the subsequence
    s -= arr[ind];
    ds.pop_back();
    printF(ind + 1, s, ds, arr, n, sum);
}

int main() {
    int arr[] = {1, 1, 2};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    printF(0, 0, ds, arr, n, sum);
    return 0;
}
// In case of returning the one subsequence, and that can be done, by playing around base conditions
#include <iostream>
#include <vector>
using namespace std;

bool printF(int ind, int s, vector<int> &ds, int arr[], int n, int sum){
    // Base case: if we have reached the end of the array
    if(ind == n){
        // If the current sum matches the desired sum, print the subsequence
        if(s == sum){
            for(auto it : ds){
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
      else  return false; 
    }
   
    // Include the current element in the subsequence
    ds.push_back(arr[ind]);
    s += arr[ind];
    if (printF(ind + 1, s, ds, arr, n, sum) == true){
        return true;
    }

    // Exclude the current element from the subsequence
    s -= arr[ind];
    ds.pop_back();
    if (printF(ind + 1, s, ds, arr, n, sum) == true){
        return true;
    }
    return false;
}

int main() {
    int arr[] = {1, 1, 2};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    printF(0, 0, ds, arr, n, sum);
    return 0;
}


// what if you want to count the number of subsequences
#include <iostream>
#include <vector>
using namespace std;

int printF(int ind, int s, int arr[], int n, int sum){
     if(ind == n){
         if(s == sum)   return true;
    
      else  return 0; 
    }
   
    s += arr[ind];
    int l =  printF(ind + 1, s, arr, n, sum);

    s -= arr[ind];
    int r = printF(ind + 1, s, arr, n, sum);
    return l+ r;
}

int main() {
    int arr[] = {1, 1, 2};
    int n = 3;
    int sum = 2;
   
    cout<< printF(0, 0, arr, n, sum);
    return 0;
}
