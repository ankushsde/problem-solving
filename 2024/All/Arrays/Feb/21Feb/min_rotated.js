
let arr = [4,5,6,7,0,1,2]
let target = 2;

// this works only for searching in sorted array using binary search
 const binarySearch = (arr,target) => {

    let low = 0;
    let high = arr.length-1;

    while (low<=high){
        let mid = Math.floor((low+high)/2)
        if(arr[mid]===target) return mid;
        else if (target>arr[mid]) low = mid + 1
        else high = mid - 1
    }
 return -1
}

const searchInRoated = (arr,target)=>{
    let low = 0;
    let high = arr.length-1;

    while (low<=high){
        let mid = Math.floor((low+high)/2)
        if(arr[mid] === target) return mid;
        else if(arr[low]<=arr[mid]){
            if(arr[low]<= target && target <= arr[mid]){
                high = mid -1
            }
            else low = mid + 1
        }
        else { 
            if(arr[mid]<=target && target <= arr[high]){
                low = mid + 1 
            }
            else { high = mid - 1}
        }

    }
  return -1 
}

const findMinInRotated = (arr) =>{
 let low = 0;
 let high = arr.length -1;

 let ans = Number.MAX_VALUE

 while (low<=high){
    let mid = Math.floor((low+high)/2)
    if(arr[low]<=arr[mid]){
        ans = Math.min(ans,arr[low])
        low = mid+1
    } 
    else{
        ans = Math.min(ans,arr[mid])
        high = mid-1
    }
 }
 return ans
}


// console.log(binarySearch(arr,target))
// console.log(searchInRoated(arr,target))
console.log(findMinInRotated(arr))