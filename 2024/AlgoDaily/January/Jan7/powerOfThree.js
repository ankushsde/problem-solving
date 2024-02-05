const num = 9

const isPowerOfThree = (num) =>{
    if(num<=0){
        return false;
    }

    const log3 = Math.log10(num) / Math.log10(3);
    console.log("check")

  // Check if the result is an integer
  return Number.isInteger(log3);
}

console.log(isPowerOfThree(num))