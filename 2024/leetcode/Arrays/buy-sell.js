let prices = [7,1,5,3,6,4]
let n = prices.length;

const findMax = (prices,n) => {
    let maxProfit = 0
    for(let i = 0; i<n ;i++){
        for(let j = i+1; j<n;j++){
            if(prices[j]>prices[i]){
                maxProfit = Math.max(prices[j]-prices[i],maxProfit)
            }
        }
    }
    return maxProfit
    //TC = O(n^2) && SC = O(1)
}

const findMax2 = (prices,n) => {
    let mini = Number.MAX_VALUE
    let max = 0
    
    for(let i = 0; i<n ; i++){
        mini = Math.min(mini,prices[i]);
        max = Math.max(max,prices[i]-mini)
    }
    return max
}


console.log(findMax2(prices,n))
// console.log(findMax(prices,n))