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
  console.log(" Hello world! ",name);
}
var name ="Ankush"
var name = "Shippi"
hoistedFunction();  

// time between hoisting and initialization of let variable is known as temporal dead zone. 


