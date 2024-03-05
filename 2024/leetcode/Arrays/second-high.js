let arr = [ -1,-2,-3,-4,-9,-5,-3,-2,-1]
let n = arr.length

const secondLargest = (arr,n)=>{
    let largest = -Infinity
    let sLargest = -Infinity

    for(let i = 0; i< n ; i++){
        if(arr[i]>largest){
            sLargest = largest
            largest =arr[i]
        }

        else if (arr[i]!== largest && arr[i] > sLargest){
            sLargest = arr[i]
        }
    }
    return sLargest
 }

console.log(secondLargest(arr,n))