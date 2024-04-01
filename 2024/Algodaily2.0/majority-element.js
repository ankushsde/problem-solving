
function majority(arr){
    let n = arr.length ;
    let el 
    let cnt = 0;
    
    for(let i = 0 ; i < n ; i++){
        if(cnt === 0){
            cnt = 1;
            el = arr[i]
        }
        else if(el === arr[i]){
            cnt++
        } else {
            cnt -- 
        }
    }
    let cnt1 = 0
    for(let i = 0; i<n;i++){
        if(arr[i] === el){
            cnt1++
        }
    }
    
    if(cnt1>Math.floor(n/2)){
        return el
    }
    return -1
}


console.log(majority([2,2,1,1,1,2,2]))