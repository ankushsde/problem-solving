// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]

let nums = [2,7,11,15];
let target = 9;

//Approach 1 : 
//TC of O(n^2) : Reason - We are running two loops each running for atleast n times.
//SC : 0 , no extra space is used

const twoSum1 = (nums,target)=>{
 let resultArr = []
 for(let i = 0 ; i<nums.length; i++){
    for(let j = 1; j< nums.length; j++){
        if(nums[i]+nums[j] === target){
            resultArr.push([i,j])
            //Instead of pushing i and j separately, it now pushes an array [i, j] to represent the pair.
        }
    }
 }
 return resultArr
}

//Approach 2 : Using hashmap
//TC : O(N) though it has O(nlogn) but we are using best case and we're dumping n elements.
const twoSum2 = (nums,target)=>{
     let hashMap = new Map
     for(let i = 0; i<nums.length;i++){
        let neededNUmber = target - nums[i]

        if(hashMap.has(neededNUmber)){
            return [i,hashMap.get(neededNUmber)]
        }
        hashMap.set(nums[i],i)
     }

    //  return hashMap
   }


console.log(twoSum2(nums,target))

