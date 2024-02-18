let arr = [1,2,3,1]
let n = arr.length
//using set 
let s = new Set(arr)

// console.log(s.size !== arr.length)

//what if you have to print an array after removing the duplicates
 

const removeDuplicates = (arr,n) =>{
    let i = 0;
    let flag = 0
    let duplicates = []
    arr.sort((a,b)=>a-b)
    for(let j = i+1; j<n ; j++){
        if(arr[j] !== arr[i]){
            i++;
            arr[i] = arr[j]
            flag = 1
        } else{
            duplicates.push(arr[j])
        }
    }
    console.log(flag == 1 ? true : false)
    console.log("Duplicate elements: ", duplicates);
    return arr.slice(0,i + 1)

}

console.log(removeDuplicates(arr,n))

 

console.log(removeDuplicates(arr,n))
