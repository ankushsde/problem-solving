let arr = [3,2,10,5,2]


//Approach 1 - Brute Force
const findLargest1 = (arr) => {
//TC for this approach wiil be O(n log n), due to sorting
let n = arr.length
arr.sort()
return arr[n-1]   
}

//Approach 2 - Optimal approach

const findLargest2 = (arr) =>{
  let largest = arr[0]
  let n = arr.length

  //TC for this approach will be O(N)
  for(let i = 0; i<n;i++){
    if(arr[i]>largest){
        largest = arr[i]
    }
  }
  return largest
}

console.log(findLargest2(arr))