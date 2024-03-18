//Brute force : TC: o(n*m)* (n+m)+(n*m)


function markRow(matrix, n, m, i) {
    // set all non-zero elements as -1 in the row i:
    for (let j = 0; j < m; j++) {
      if (matrix[i][j] !== 0) {
        matrix[i][j] = -1;
      }
    }
  }
  
  function markCol(matrix, n, m, j) {
    // set all non-zero elements as -1 in the col j:
    for (let i = 0; i < n; i++) {
      if (matrix[i][j] !== 0) {
        matrix[i][j] = -1;
      }
    }
  }
  
  function zeroMatrix(matrix, n, m) {
    // Set -1 for rows and cols that contains 0. Don't mark any 0 as -1:
    for (let i = 0; i < n; i++) {
      for (let j = 0; j < m; j++) {
        if (matrix[i][j] === 0) {
          markRow(matrix, n, m, i);
          markCol(matrix, n, m, j);
        }
      }
    }
    // Finally, mark all -1 as 0:
    for (let i = 0; i < n; i++) {
      for (let j = 0; j < m; j++) {
        if (matrix[i][j] === -1) {
          matrix[i][j] = 0;
        }
      }
    }
    return matrix;
  }
  
  const matrix = [
    [1, 1, 1],
    [1, 0, 1],
    [1, 1, 1],
  ];
  
  const n = matrix.length;
  const m = matrix[0].length;
  
  const ans = zeroMatrix(matrix, n, m);
  
  console.log("The Final matrix is: ");
  for (let i = 0; i < n; i++) {
    console.log(ans[i].join(" "));
  }

// Better Approach  time complexity  :O(n^2)
//We create row and col of length n and m and mark them 0 initially and once we found any 0 in a 
// particular row or column, we'll mark them as 1
//after that, we'll run a nested for loop, where if(row[i] || col[j] === 1) we'll mark the matrix, 
// row's and columns as 0

function zeroMatrix2(matrix, n, m) {
    let row = Array(n).fill(0);
    let col = Array(m).fill(0);
 
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (matrix[i][j] === 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
 
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (row[i] === 1 || col[j] === 1) {
                matrix[i][j] = 0;
            }
        }
    }
 
    return matrix;
 }

