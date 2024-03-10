let strs = ["eat","tea","tan","ate","nat","bat"]

function groupAnagrams (strs) {

    const mp = new Map()
    let ans = []

    for(let i = 0; i<strs.length; i++){
        const str = strs[i];
        const sortedStr = str.split('').sort().join('');

        if(mp.has(sortedStr)){
            ans[mp.get(sortedStr)].push(str)
        }else{
            mp.set(sortedStr,ans.length)
            ans.push([str])
        }
        // ans.push(sortedStr)
    }

    return ans
}

console.log(groupAnagrams(strs))































// Approach 2
// Using an Unordered Map: We utilize an unordered map to store the sorted version of each string (anagram) as the key and the index of the corresponding group in the answer vector as the value. This allows us to quickly check if an anagram group already exists.

// Iterating Through the Input Strings: We iterate through each string in the input vector 'strs'.

// Sorting Strings: For each string, we sort its characters alphabetically. This ensures that anagrams will have the same sorted representation.

// Grouping Anagrams: We check if the sorted string exists in the unordered map. If it does, we add the current string to the corresponding group in the answer vector. If not, we create a new group and store its index in the unordered map.

// Returning the Answer: Once all strings have been processed, we return the answer vector containing the grouped anagrams.

