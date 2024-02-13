const arr = [5,1,3,2,6]


const odds = arr.filter((arr)=>{
   return arr % 2 === 1
})

const even = arr.filter((arr)=>{
    return arr % 2 === 0
})

 

const output = arr.filter((x)=>{
    return x % 2 
})

const output2 = arr.filter(item=>item == 3)

const mapOutput = arr.map(item=>item == 3)
console.log("odds",odds);
console.log("even",even);

