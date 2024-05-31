//object
var obj = {
    x: 43,
    y: "Hello World",
    z: function(){
        return this.x;
    }
}
const res = obj.z();
 
//hoisting :--> is a mechanism in js, where all the variables and function declaration are moved to the top
// This means that irrespective of where the variables abd functions are declared

// declaration is hoisted, but not the initialization

// var is cool, up for updation and redelaration,
// let is little moodu, only allow updation
// const is super strict, allows nothing

function hoistedFunction(){ 
  // console.log(" Hello world! ",name);
}
var name ="Ankush"
var name = "Shippi"
hoistedFunction();  

// time between hoisting and initialization of let variable is known as temporal dead zone. 

//This keyword
// this keyword refers to the current context or scope within which the code is executing, it's value is
// determined by how a fucntion is called, 

// Closures : functions bundled together with its lexical scope
// examples : Currying, memoization, setTimeouts

// Prototype inheritance: 
// Inheritance in js is quite different, 
// JS engine attaches our created objects with hidden properties, also for functions, etc:
// attaches an object to the original object. 
// prototype attaches objects
 


