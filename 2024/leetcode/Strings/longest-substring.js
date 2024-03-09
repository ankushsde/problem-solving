let str = "abcabcbb";

//Brute Force : TC: O(n^2) USING SET
function solution1(s) {
  let maxAns = Number.MIN_SAFE_INTEGER;
  for (let i = 0; i < s.length; i++) {
    let set = new Set();
    for (let j = 0; j < s.length; j++) {
      if (set.has(str[j])) {
        maxAns = Math.max(maxAns, j - i);
        break;
      }
      set.add(str[j]);
    }
  }
  return maxAns;
}

//Optimised Approach : Using Two pointers

function solution2() {github

    
  if (str.length === 0) return 0;
  let maxans = Number.MIN_SAFE_INTEGER;
  let set = new Set();
  let l = 0;
  for (let r = 0; r < str.length; r++) {
    // outer loop for traversing the string
    if (set.has(str[r])) {
      // if duplicate element is found
      while (l < r && set.has(str[r])) {
        set.delete(str[l]);
        l++;
      }
    }
    set.add(str[r]);
    maxans = Math.max(maxans, r - l + 1);
  }
  return maxans;
}

console.log(solution1(str));
