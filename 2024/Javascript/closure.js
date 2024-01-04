function a(){
    let x = 5
    function b(){
        console.log(x)
    }
    b()

}

let z = a( );

//a function that bind with its lexical enviornment.
// lexical enviornment : whenever an execution context is created lexical enviornment is also created.
// lexical enviornment is the local memory along with the enviornment of its parent.
 
  