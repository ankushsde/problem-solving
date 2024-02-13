let nums = [1,2,3,4,4];
let n = nums.length;

const findDuplicates = () => {
   let s = new Set(nums)
   return s.size !== nums.length
 };

const findDuplicates2 = (nums)=>{
  nums.sort((a,b)=>a-b)
  let flag = 0;
  for(let i = 0; i<n;i++){
    if(nums[i] === nums[i+1]){
        flag =1
    }
  }
  return flag==1 ? true : false
}
console.log(findDuplicates2(nums, n));
