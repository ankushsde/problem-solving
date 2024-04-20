//Flyod Warshall : 

// This is a multisource shoretest path algorithm, helps in detecting negative cycles as well. 
// psudo code : 


//to ensure that every weight is marked as infinity
int n = matrix.size();

for(int i = 0; i<n; i++){
 for(int j = 0; j<n; j++){
  if(matrix[i][j] == -1){
   matrix[i][j] = 1e9;
  }
//also mark diagonal to be zero.
if(i==j) matrix[i][j] = 0;
 }
}

for( int k = 0; k < n ; k++){
for ( int i = 0; i < n ; i++) {
 for (int j = 0; j < n ; j++){
   matrix[i][j] = min(matrix[i][k] + matrix[k][j])
 }
} 
}

// and also remember when returning the matrix, change the infinity concept;

for(int i = 0; i<n; i++){
  for(int j = 0; j<n; j++){
   if(matrix[i][j] == 1e9){
   matrix[i][j] = -1
    }
  }
}

// to detect a cycle : 
 for(i—>n){
  if(matrix[i][j]<0){
   cout<<"Negative cycle"<<endl;
}
}

// TC: O(N^3) and SC= 0(N^3) , SC depends on the space occupied, and we're using a matrix that costs us n*n
