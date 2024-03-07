let arr = [ -1,-2,-3,-4,-9,-5,-3,-2,-1]
let n = arr.length


//brute force  Tc : nlogn + n

const findSecondLargest = (arr,n) => {
    arr.sort((a,b)=>a-b)
    let largest = arr[n-1]
    let secondLargest;
    for(let i = n-2; i>=0; i-- ){
        if(arr[i]!== largest){
            secondLargest = arr[i]
            break;
        }
        
    }
    return secondLargest
}

console.log(findSecondLargest(arr,n))

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

// console.log(secondLargest(arr,n))