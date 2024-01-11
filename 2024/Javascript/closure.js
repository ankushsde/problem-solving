function a(){
    let x = 5
    function b(){
        console.log(x)
    }
    b()
}

// let z = a( );

//a function that bind with its lexical enviornment.
// lexical enviornment : whenever an execution context is created lexical enviornment is also created.
// lexical enviornment is the local memory along with the enviornment of its parent.
 

let printValue = () => {
    for(var i = 1;  i <=5;i++){
      function inside(x){
        setTimeout(function(){
            console.log(x);
        }, x * 1000)
      }
      inside(i)
    }
}


printValue()

