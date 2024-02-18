let nums = [8,8,7,7,7]
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

//Using hashing

const majorityElement2= (arr,n)=> {
    let map = new Map

    for(let i = 0; i< n; i++){
        let num = arr[i]
        if(map.has(num)){
            map.set(num,map.get())
        }
    }
}

console.log(majorityElement2(nums,n))