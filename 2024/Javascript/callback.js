// function sendMessage (message){
//     console.log(message)
// }

// function getMessage(sendMessage){
//     const message = "This is a secret message"
//     sendMessage(message)
// } 

// getMessage(sendMessage)


//A callback function is a function that is passed as an argument to another function.
//and it is executed after some operation/event is executed.

// setTimeout(function(){
//  console.log("timer")
// },5000)

// function x(y){
//     console.log("x")
//     y();
// }

// x(function y (){
//     console.log("y")
// })



document.getElementById("clickMe").addEventListener("click",function xyz(){
 console.log("Button Clicked")
})


