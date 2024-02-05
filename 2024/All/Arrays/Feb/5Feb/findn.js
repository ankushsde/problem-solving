//given the number 'n'. Find out the number of digits present in a number and return.

let number = 7877989;
let n = number.toString().length;
 

const findNumber = (n) => {
  let count = 0;
  while (n > 0) {
    count=count+1
    n = Math.floor(n/10)
  }
  return count;
};

console.log(findNumber(number));
