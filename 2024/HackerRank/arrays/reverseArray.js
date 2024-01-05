let a = [1,4,3,2]
function reverseArray(a) {
    let n = a.length;
    let arr = [];
    for(let i = n-1; i>=0 ; i--){
        arr.push(a[i])
    }
return arr;
}

console.log(reverseArray(a))