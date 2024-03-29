let arr = [1, 2, 3, 4, 5, 6, 7];
let k = 3;
let n = arr.length;

const rotateArr = (arr, k, n) => {
  k = k % n;
  let temp = new Array(k);
  for (let i = n - k; i < n; i++) {
    temp[i - n + k] = arr[i];
  }
  for (let i = n - k - 1; i >= 0; i--) {
    arr[i + k] = arr[i];
  }
  for (let i = 0; i < k; i++) {
    arr[i] = temp[i];
  }
  return arr;
};


// TC: O(n) , SC= k
console.log(rotateArr(arr, k, n));

// function reverseFnc (arr,start,end){
//   while (start<=end){
//    let temp = arr[start]
//    arr[start] = arr[end]
//    arr[end] = temp
//    start++;
//    end--;
//   }
// }

const rotateArr2 = (a, k, n) => {
  k = k % n;
  a.reverse(a,a+k)
  a.reverse(a+k,a+n)
  a.reverse(a,a+n)
  return a
};

console.log(rotateArr2(arr, n, k))
