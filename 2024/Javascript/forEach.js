let arr = [1,2,3,4,5]

const odd = arr.map((elmnt)=>{

    return  elmnt +1
}).filter((elmnt)=>{
    return elmnt> 4
}).reduce((acc,curr)=>{
  return acc += curr
},0)

 

console.log("odd",odd)

function test(...args) {
    console.log(typeof args);
   }
   test(12);