var expect = function(val) {
    return {
       toBe : (val2) => {
           if(val !== val2) throw new Error("Not Equal")
           else return true
       },
       notToBe: (val2) => {
           if(val === val2) throw new Error("Equal")
           else return true
       }
     
   }
};

//to be or not to be

 

const createCounter = (val) =>{
    let presentCount = val
     return {
         increment : () => ++presentCount, 
         decrement: () => --presentCount,
         reset: ( ) =>  presentCount = val
     }
     
 }
 
 const counter = createCounter(5)
 console.log(counter.increment())
 console.log(counter.decrement())
 console.log(counter.reset())
 
 