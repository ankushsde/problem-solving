let arr = [1,2,4,5,6,7,8,9,9]
let n = arr.length

let secondLargest = (arr)=>{
   let largest = arr[0];
   let secondLargest = -1
   for(let i = 0; i<n;i++){
    if(arr[i]>largest){
        secondLargest=largest;
        largest = arr[i];
    }
   }
   return secondLargest; 
}


console.log(secondLargest(arr))

