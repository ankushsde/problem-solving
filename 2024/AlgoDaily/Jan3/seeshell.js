const reverseOnlyAlphabetical = (string) => {
    let arr = [];
    let n = string.length;

    // Create an array of indices and characters of alphabetical characters
    let alphaChars = [];
    for(let i = 0; i<n;i++){
        if(/[a-zA-Z]/.test(string[i])){
            alphaChars.push({index:i,char:string[i]})
        }
    }

    for(let i = 0; i<alphaChars.length; i++){
        arr[alphaChars[i].index]= alphaChars[alphaChars.length-1-i].char;
    }
    for(let i = 0; i< n ; i++){
        if(!arr[i]){
            arr[i]=string[i]
        }
    }


    return arr.join("");
}

console.log(reverseOnlyAlphabetical('sea!$hells3'));
