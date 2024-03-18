function isAnagram(s1,s2){
    let sortedStr1 = s1.split('').sort().join('')
    let sortedStr2 = s2.split('').sort().join('')

    return sortedStr1===sortedStr2
}

console.log(isAnagram("cinema","icemn"))