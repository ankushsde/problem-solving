let arr= [1,0,2,0,3,0,4,0,5]
let n = arr.length

const moveZeores = (arr) => {
    let temp = []
    for(let i = 0 ; i < n ; i++){
        if(arr[i]!=0){
            temp.push(arr[i])
        }
    }

    arr = temp;

    for(let i = temp.length; i<n ; i++ ){
        arr[i]=0;
    }

    return arr
}

console.log(moveZeores(arr))