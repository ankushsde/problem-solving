// Brute is do wha the question is saying by marking all the rows and colums as -1, and later on looping around at make -1 to be zero, 
// Tc: will be somewhere close to N^3

// Better Solution 
// We'll be using extra pair of arrays for row and col and initially they will be marked as zero,
// check while looping in a matrix that if any element is 0, if yes, mark the row and col array with 1
// run a loop and if row and col consist of 1 mark that row and col as zero, this is better but still we have extra space, right? 
// TC: O(2(N*M)) SC: O(N+M)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n,0);
        vector<int> col(m,0);

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }

        for(int i = 0; i<n; i++ ){
            for(int j = 0; j<m; j++){
                if(row[i] || col[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

// We'll look for better soultion in the next revision