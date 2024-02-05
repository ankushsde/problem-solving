let nums = [2,2,1,1,2,2]
let n = nums.length

const majorityElement = (nums,n) =>{
    let cnt = 0 ;
    for(let i = 0; i<n; i++){
        for(let j = 1; j<n; j++){
            if(nums[j]==nums[i]){
                cnt++
            }
        }
        if(cnt>n/2){
            return nums[i]
        }
    }
}

console.log(majorityElement(nums,n))