function sumOfAllNumbers(nums){
    let sum = 0;
    for(let i = 1; i<=nums;i++){
        sum = sum + i;
    }
    
    return sum;
}

console.log(sumOfAllNumbers(3))