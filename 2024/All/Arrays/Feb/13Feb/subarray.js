let arr = [-1]
let n = arr.length

const maxSubArray = (arr,n) =>{
     let sum = 0; 
     let maxi = Number.MIN_SAFE_INTEGER
     let ansStart = -1
     letansEnd = -1
     
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

console.log(maxSubArray(arr,n))