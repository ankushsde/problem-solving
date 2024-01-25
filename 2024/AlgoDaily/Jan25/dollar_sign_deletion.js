function isDollarDeletionEqual(input) {
  for (let i = 0; i < input.length - 1; i++) {
    const str1 = applyDeleteAction(input[i]);
    const str2 = applyDeleteAction(input[i + 1]);

    if (str1 !== str2) {
      return false;
    }
  }
  return true;
}

function applyDeleteAction(str) {
  
    if(typeof str !== 'string'){
        return str
    }
    const chars = str.split('');
    for(let i = 0; i <chars.length;i++){
        if(chars[i]==='$'){
            chars.splice(i-1,3);
            i-=2
        }
    }

  return chars.join('')
}
console.log(applyDeleteAction('helloB$rother'))

let input = ["f$st", "st"];
console.log(isDollarDeletionEqual(input));
