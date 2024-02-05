function sumDigitUntilOne (num){
    while (num>=10){
        num = sum(num)
    }
    return num
    
}
function sum (num){
    let sum = 0;
    while (num>0){
        sum += num % 10;
        num = Math.floor(num/10)
    }

    return sum;

}
// console.log(sumDigitUntilOne(49))
const result = sumDigitUntilOne(49)
console.log(result)