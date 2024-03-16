let i = 0;

function increment() {
    return i + 1;
}

function debounce (func,wait){
  
    let timeoutId = null 
    return function(...args){
        const context = this;
        clearTimeout(timeoutId)
    
        timeoutId = setTimeout(function(){
          timeoutId = null
          func.apply(context,args)
        },wait)
      }
}

const debouncedIncrement = debounce(increment, 100);

console.log(debouncedIncrement()); // This will schedule the execution of `increment` after 100 milliseconds
 
    console.log(debouncedIncrement()); // This will be debounced and won't execute immediately
 setTimeout(() => {
    console.log(debouncedIncrement()); // This will be debounced and won't execute immediately
}, 150); // Call again after the debounce time (100 milliseconds)