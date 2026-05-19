// q1_max_subarray.js
// ─────────────────────────────────
// TOPIC    : Kadane's Algorithm
// QUESTION : Maximum Subarray Sum
// ─────────────────────────────────

// BRUTE FORCE - O(n²)
function maxSum_brute(A) {
    let max = A[0];
    for (let i = 0; i < A.length; i++) {
        let curr = 0;
        for (let j = i; j < A.length; j++) {
            curr += A[j];
            max = Math.max(max, curr);
        }
    }
    return max;
}

// OPTIMAL - O(n)
function maxSum(A) {
    let curr = A[0];
    let max = A[0];
    for (let i = 1; i < A.length; i++) {
        curr = Math.max(A[i], curr + A[i]);
        max = Math.max(max, curr);
    }
    return max;
}

// TEST CASES
console.log("─── Brute Force ───");
console.log(maxSum_brute([-2,1,-3,4,-1,2,1,-5,4])); // 6
console.log(maxSum_brute([-3,-1,-2,-4]));            // -1

console.log("─── Optimal ───");
console.log(maxSum([-2,1,-3,4,-1,2,1,-5,4]));       // 6
console.log(maxSum([-3,-1,-2,-4]));                  // -1