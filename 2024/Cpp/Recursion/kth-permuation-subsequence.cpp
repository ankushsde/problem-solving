// Brute force 
// approach: using recursive way, 
// 1) generate all the permutations
// 2) once all the permutaions are generated put them in any data structure
// 3) sort the data structure, kth position will be present in the ds[K-1] position
// TC: too much, I'll try, for step1 - O(n!) + deep copying O(n) + sort(n!logn!) 

// Better appraoch : 
// assume n=4 , k = 17 
// there could be 4 variations while generating the permutaion, 4!
// we can have our permutation starting with either 1 or 2 or 3 or 4. 
// if the first position is already occupied by one number there are three more positions left.
// the remaining three numbers can be permuted among themselves while filling the 3 positions and will generate 3! = 6 sequences.
// each block will have 6 permutations adding up to a total of 6*4 = 24 permutations. 
//TC: o(N^2), SC: O(N)

#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string getPermutation(int n, int k) {
      int fact = 1;
      vector < int > numbers;
      for (int i = 1; i < n; i++) {
        fact = fact * i;
        numbers.push_back(i);
      }
      numbers.push_back(n);
      string ans = "";
      k = k - 1;
      while (true) {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0) {
          break;
        }

        k = k % fact;
        fact = fact / numbers.size();
      }
      return ans;
    }
};

int main() {
  int n = 3, k = 3;
  Solution obj;
  string ans = obj.getPermutation(n, k);
  cout << "The Kth permutation sequence is " << ans << endl;

  return 0;
}
