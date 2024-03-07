let arr = [2,11,7,15]

let n = arr.length



const twoSum = (arr,n) =>{
    // let target = 9
    // let sumarr = []
    // for(let i = 0; i<n ; i++){
    //     for(let j = i+1; j<n;j++){
    //     if(arr[i]+arr[j] == target){
    //         sumarr.push(i,j)
    //     }
    // }
    // }
    // return sumarr

    let target = 9;
    let sumArr = [];

    for(let i = 0; i<n; i++){
     for(let j = i+1; j<n;j++){
        if(arr[i]+arr[j]===target){
            sumArr.push(i,j)
        }
     }
    }
    return sumArr

}

const twoSum2 = (arr,n) => {
    let target = 9
    let hashMap = new Map;

    for(let i = 0; i< n ; i++){
        let neededNUmber = target - arr[i];
        if(hashMap.has(neededNUmber)){
            return [i,hashMap.get(neededNUmber)]
        }
        hashMap.set(arr[i],i)
    }
}

// console.log(twoSum2(arr,n))
console.log(twoSum(arr,n))