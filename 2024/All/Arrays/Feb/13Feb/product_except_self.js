let arr = [1, 2, 3, 4];
let n = arr.length;
let product = 1;
const findProduct = (arr) => {
   
    let prefix = []
   
    for(let i = 0; i<n;i++){
    if(i ===0){
        prefix[i]=1
    }else {
        prefix[i]=arr[i-1]* prefix[i-1]
    }
   }   

   let suffix = []

   for (let i = n-1; i>=0; i--){
     if(i === n-1){
       suffix[i]=1
     } else {
        suffix[i]= arr[i+1]* suffix[i+1]
     }
   }

   let result = []
   for(let i = 0; i<n;i++){
    result[i]= prefix[i]*suffix[i]
   }

   return result

};

console.log(findProduct(arr));
