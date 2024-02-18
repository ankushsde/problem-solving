let arr =[1,1,2,2,3,3,3]

const removeDuplicates = (arr) => {

    let i = 0;
    let n = arr.length;
     for(let j = 0; j<n; j++){
        if(arr[j]!=arr[i]){
            i++;
            arr[i]=arr[j]
             
        }

    }
  return arr.slice(0,i+1)
}

console.log(removeDuplicates(arr))