let arr = [1,2,3,4,5,5]
let n = arr.length
const reversedArray = (arr) => {
     let newArr = []
     for (let i = n-1 ; i>=0 ; i--){
        newArr.push(arr[i])
     }
     return newArr
}

const reverseArray = (arr) => {
   for(let i = 0; i<n/2; i++){
       let temp = arr[i];
       arr[i] = arr[n-i-1];
       arr[n-i-1] = temp;
   }
   return arr
}

console.log(reversedArray(arr))

// console.log("reversed using predefined ", arr.slice().reverse())

