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

console.log(isAnagram("cin ema", "iceman"));  // Should return true


function checkAnagram (s,t){

    if (t.length !== s.length) return false;
    const charFrequency = new Map();
    for (let i = 0; i < s.length; i++) {
        charFrequency.set(s[i], (charFrequency.get(s[i]) || 0) + 1);
        charFrequency.set(t[i], (charFrequency.get(t[i]) || 0) - 1);
    }
    for (const [char, count] of charFrequency) {
        if (count !== 0) return false;
    }
    return true;

}

function isAnagramObject(s, t) {
    if (s.length !== t.length) return false; // Check if lengths are equal

    const charFrequency = {}; // Object to store character frequencies

    // Iterate through each character of both strings
    for (let i = 0; i < s.length; i++) {
        // Increment frequency for s[i]
        charFrequency[s[i]] = (charFrequency[s[i]] || 0) + 1;
        // Decrement frequency for t[i]
        charFrequency[t[i]] = (charFrequency[t[i]] || 0) - 1;
    }

    // Check if all character frequencies are 0
    for (let count of Object.values(charFrequency)) {
        if (count !== 0) return false;
    }

    return true; // Strings are anagrams
}


console.log(checkAnagram("listen","silent"))



//Algorithm

// Check if the lengths of the two input strings are equal. If not, return false.
// Create a map (or object) to store character frequencies.
// Iterate through each character of both strings simultaneously.
// For each character in the first string, increment its frequency in the map.
// For each character in the second string, decrement its frequency in the map.
// After iterating through both strings, iterate through the map:
// If any character has a non-zero frequency, return false.
// If all characters have a frequency of zero, return true, indicating that the strings are anagrams.
