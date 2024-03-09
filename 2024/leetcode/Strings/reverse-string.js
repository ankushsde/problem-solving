let s = " this is a blue sky "

function reverseWords(s){
    
    s = s.split(' ')
    let res= []
    for(let i = s.length - 1; i>=0; i--){
        if(s[i]!= '') res.push(s[i])
    }

    return res.join(' ')
  
}
console.log(reverseWords(s))