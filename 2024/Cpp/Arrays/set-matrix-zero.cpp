#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix , int n, int m){
    int row[n] = {0};
    int col[m]={0};
    
    // in case of using void function 
    vector<int>  col(n,0)
    vector<int> row(m,0)
    
    for(int i = 0; i< n; i++){
        for(int j = 0; j<m; j++){
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    };

   for(int i = 0; i<n ; i++){
       for(int j = 0; j< m ; j++){
           if(row[i] || col[j]){
               matrix[i][j]=0;
           }
       }
       
       
   };
   
 return matrix;
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix.size();
    vector<vector<int>> ans  = zeroMatrix(matrix,n,m);
    cout << "Final output of the matrix";
   
     for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        // cout << "n";
    }
    
    return 0;
}