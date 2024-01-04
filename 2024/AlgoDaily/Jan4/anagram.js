const isAnagram = (str1, str2) => {
    const clearStr1 = str1.replace(/[^a-zA-Z0-9]/g,'').toLowerCase()
    const  clearStr2 = str2.replace(/[^a-zA-Z0-9]/g,'').toLowerCase()

     if(clearStr1.length !== clearStr2.length){
        return false;
     }

     const sortedStr1 = clearStr1.split('').sort().join('')
     const sortedStr2 = clearStr2.split('').sort().join('')
    return sortedStr1 === sortedStr2
}

console.log(isAnagram("cinema", "iceman"));  // Should return true
