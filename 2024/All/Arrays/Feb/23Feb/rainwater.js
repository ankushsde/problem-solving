let arr = [0,1,0,2,1,0,1,3,2,1,2,1]
let n = arr.length


const findWater = (arr,n) =>{

    let waterTrapped = 0;
    for(let i = 0; i< n ; i++){
        let j = i 
        let leftMax = 0
        let rightMax = 0

        while (j>=0){
            leftMax = Math.max(leftMax,arr[j]);
            j--;
        }
        j = i;
        while(j<n){
            rightMax = Math.max(rightMax,arr[j])
            j++;
        }
        waterTrapped += Math.min(leftMax,rightMax) - arr[i]
    }
    return waterTrapped;
}

console.log(findWater(arr,n))