const nums1 = [4,9,5];
const nums2 = [9,4,9,8,4];
const n1 = nums1.length;
const n2 = nums2.length;


const intersection =(nums1,nums2)=>{
  const set = new Set(nums1);
  const filteredSet = new Set(nums2.filter((n)=>set.has(n)))
  return [...filteredSet]
}
const intersection2 = (nums1,nums2,n1,n2) => {
 let i = 0;
 let j = 0;
 let ans = []

 while(i<n1 && j<n2){
    if(nums1[i]<nums2[j]){
        i++;
    }
    else if(nums2[j]<nums1[i]){
        j++;
    }
    else {
        ans.push(nums1[i]);
        i++;
        j++;
    } 
 }
 return ans
}

console.log(intersection(nums1,nums2,n1,n2))

//TC = O(N^2)
const intersection1 = (nums1,nums2) => {
    let temp = []
    let k = 0;
       for(let i = 0; i<n1;i++){
        for (let j = 0;j<n2;j++){
            if(nums1[i]==nums2[j] ){
                temp.push(nums1[i]);
                break;
            }
        } 
       }
    
       return temp;
    }