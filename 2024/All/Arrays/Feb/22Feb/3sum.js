let arr = [-1, 0, 1, 2, -1, -4];

let n = arr.length;

const threeSum = (arr, n) => {
  let ans = [];
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      for (let k = j + 1; k < n; k++) {
        if (arr[i] + arr[j] + arr[k] === 0) {
          let temp = [arr[i], arr[j], arr[k]];
          temp.sort((a, b) => a - b);
          ans.push(temp);
        }
      }
    }
  }
  let set = new Set(ans.map(JSON.stringify));
  ans = Array.from(set).map(JSON.parse);

  return ans
 };

// console.log(threeSum(arr, n));

const result = threeSum(arr,n)

for (let i = 0; i < result.length; i++) {
     
  }

// console.log(result)

/// Better Approach

let ans = [];
arr.sort((a, b) => a - b);
for (let i = 0; i < n; i++) {
    // remove duplicates:
    if (i !== 0 && arr[i] === arr[i - 1]) continue;

    // moving 2 pointers:
    let j = i + 1;
    let k = n - 1;
    while (j < k) {
        let sum = arr[i] + arr[j] + arr[k];
        if (sum < 0) {
            j++;
        } else if (sum > 0) {
            k--;
        } else {
            let temp = [arr[i], arr[j], arr[k]];
            ans.push(temp);
            j++;
            k--;
            // skip the duplicates:
            while (j < k && arr[j] === arr[j - 1]) j++;
            while (j < k && arr[k] === arr[k + 1]) k--;
        }
    }
}
return ans;