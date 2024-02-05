let arr = [3,2,1,5,2,10,9]
let n = arr.length;

const largestElement = (arr)=>{
   let  largest = arr[0];
   for(let i = 0; i<n; i++){
    if(arr[i]>largest){
        largest = arr[i]
    }
        //to print the index of element use indexOf() eg : arr.indexOf(arr[j])
   }
   return largest;

}

console.log(largestElement(arr))
// TC = O(N)