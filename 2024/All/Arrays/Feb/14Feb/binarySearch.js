let nums = [3,4,6,7,9,12,16,17];
let target = 6
let n = nums.length;

const binarySearch = (nums, n, target) => {
    let low = 0;
    let high = n-1;
    
    while(low<=high){
        let mid = Math.floor((low+high)/2)
        if(nums[mid] == target) return mid;
        else if(target> nums[mid]) low = mid + 1;
        else high = mid -1 
    }
    return -1
};

let result= binarySearch(nums, n,target);

if(result === -1) return "Element is not present"
else console.log("The targest is present at ",result)