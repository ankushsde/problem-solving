//console.log(this)

const person = {
    name:"Ankush",
    introduce:function(){
        console.log("the name is",this.name)
    }
}
 person.introduce()

// sum(1,2)

function sum(a,b){
    return function(c,d){
        return a+b+c+d;
    }
}
let result = sum(1,3)(4,2)

console.log(result)