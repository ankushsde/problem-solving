const arr = [5,1,3,2,6]

 

const output = arr.filter((x)=>{
    return x % 2 
})

const output2 = arr.filter(item=>item == 3)

const mapOutput = arr.map(item=>item == 3)
console.log(mapOutput);

