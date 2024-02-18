let arr = [1,2,4,5,7,7]

let n = arr.length;

const secondLargest = (arr,n) => {
let largest = arr[0]
let slargest = -1

for(let i = 0; i<n;i++){
  if(arr[i]>largest){
    slargest = largest;
    largest = arr[i]
  } else if(arr[i]>slargest && arr[i]!=largest){
    slargest = arr[i]
  }
}
return slargest

}

console.log(secondLargest(arr,n))