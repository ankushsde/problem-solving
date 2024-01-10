const num = 26


const isPowerOfTwo = (num) => {
 if(num<=0){
    return false

 }
 const log2 = Math.log2(num) // power of two 
 const log5 = Math.log10(num)/Math.log10(5)   // power of 5 
 
 return Number.isInteger(log2)
}

console.log(isPowerOfTwo(num))