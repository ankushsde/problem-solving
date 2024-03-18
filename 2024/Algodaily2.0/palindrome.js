function isPalindrome(str){
    
    let temp = []
    for(let i = str.length - 1 ; i>=0 ;  i--){
        temp.push(str[i])
    }
    return temp.join('') === str

}

console.log(isPalindrome("racecar"))

// special case : if string has spaces ? clean the string uring regex
// like : let cleanstr = str.replace(/[^a-zA-Z0-9]/g,'')

// if there's any capital letters : use: toLowerCase()