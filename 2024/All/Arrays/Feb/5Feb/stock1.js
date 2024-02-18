let prices =[7,6,4,3,1]
let n = prices.length

const buySellStock = (prices,n) =>{
  let profit = 0;
  let mini = prices[0]
    for(let i =1; i<n;i++){
         let cost = prices[i]-mini;
         profit = Math.max(profit,cost);
         mini = Math.min(mini,prices[i])
    }
    return profit
}

console.log(buySellStock(prices,n))