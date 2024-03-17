function reverseOnlyAlphabetical(s){
    let result = ' '
    let stack = []
    const isAlphabetical = (char) => /[a-zA-Z]/.test(char)
    for(let i = 0; i< s.length; i++){
        if(isAlphabetical(s[i])){
            stack.push(s[i])
        }
    }
    for(let i = 0; i<s.length; i++){
        if(isAlphabetical(s[i])){
            result += stack.pop();
        }
        else {
            result += s[i]
        }
    }
    return result
}


console.log(reverseOnlyAlphabetical('Test1ng-Leet=code-Q!'));


