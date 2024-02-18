function findMajorityElement(nums) {
    // Initialize variables to keep track of the potential majority element and its count
    let candidate = nums[0];
    let count = 1;

    // Iterate through the array starting from the second element
    for (let i = 1; i < nums.length; i++) {
        // If count becomes zero, update the candidate
        if (count === 0) {
            candidate = nums[i];
            count = 1;
        }
        // If the current element is the same as the candidate, increment the count; otherwise, decrement it
        else if (nums[i] === candidate) {
            count++;
        } else {
            count--;
        }
    }

    // At this point, the candidate is a potential majority element
    // You can optionally verify if it occurs more than half the time in the array

    return candidate;
}

// Example usage
const nums = [4, 2, 4, 2];
const result = findMajorityElement(nums);
console.log("Majority Element:", result);
