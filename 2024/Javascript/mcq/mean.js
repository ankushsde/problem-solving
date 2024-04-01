
function mean(arr){
    
    let n = arr.length
    let sum = 0
    for(let i = 0; i< n; i++){
        sum += arr[i]
    }
    return n>=1 ? sum/n : 'NaN' 
}


console.log(mean([4, 2, 8, 6]))