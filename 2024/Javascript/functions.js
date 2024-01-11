

// function statement

function a(){
    console.log("a is called")
}

//function Expression

var b = function (){
    console.log(" b is called")
}

// Function Declaration : This is similiar to function statement 

//Anonyms functions

// function () {

// }    these functions are used in a place where functions are used as values.


//named Function Expressions

var c = function xyz(){
 let x = 5;
 var y = 6;

 if(x++ === --y){
  console.log("Yes")
 } else{ console.log("No")}
}
c()

