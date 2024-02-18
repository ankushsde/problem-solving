let arr = [-1]
let n = arr.length

const maxSubArray = (arr,n) =>{
     let sum = 0; 
     let maxi = Number.MIN_SAFE_INTEGER     
     for(let i = 0; i<n;i++){
         if(sum === 0) 
         sum +=arr[i]
         if(sum>maxi){
             maxi = sum
         }
         if(sum < 0){
             sum = 0
         }
     }
     return maxi
}

// console.log(maxSubArray(arr,n))


//another way using kadane's 

const kadane = (arr,n) => {
    return false
}

console.log(kadane(arr,n))