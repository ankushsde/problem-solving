let arr = [7,6,4,3,1]
let n = arr.length
//bruteForce
const findProfitbf = (arr,n) =>{
  let maxProfit = 0
  for(let i = 0; i<n; i++){
    for(let j = i+1; j<n; j++){
        if(arr[j]>arr[i]){
            maxProfit= Math.max(arr[j]-arr[i],maxProfit)
        }
    }
  }
  return maxProfit
}

//optimal approach

const findProfito = (arr,n) =>{

    let minProfit = Math.MAX_VALUE;
    let maxProfit = 0;

    for(let i = 0 ; i < n ; i++){
    
        minProfit = Math.Min(minProfit,arr[i]);
        maxProfit = Math.Max(maxProfit,arr[i]-minProfit)
    }
    return maxProfit;

}

console.log(findProfitbf(arr,n))