let arr = [3,4,0,40,33,0,22,11,0,20,8]

function moveZeros(arr) {
    let zeros = [];
    arr = arr.filter((item) =>
     (item !== 0 ? true : zeros.push(item) && false)
     );
    return arr.concat(zeros);
 }

let result = moveZeros(arr)
console.log(result)