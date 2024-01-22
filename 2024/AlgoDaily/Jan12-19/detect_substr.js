function findSubstringIndex(str, substr) {
    for (let i = 0; i <= str.length - substr.length; i++) {
      let match = true;
      for (let j = 0; j < substr.length; j++) {
        if (str[i + j] !== substr[j]) {
          match = false;
          break;
        }
      }
      if (match) {
        return i; // Return the index where the substring is found
      }
    }
    return -1; // Return -1 if the substring is not found
  }
  
  let str1 = "home is where your cat is";
  let substr = "cat";
  console.log(findSubstringIndex(str1, substr)); // Output: 20
  