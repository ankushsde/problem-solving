let isPalindrome = (str) => {
    let n = str.length;
    let reversedArr = [];
    let cleanStr = str.replace(/[^a-zA-Z0-9]/g, "").toLowerCase();
    for (let i = n - 1; i >= 0; i--) {
      reversedArr.push(cleanStr[i]);
    }
    let sortedstr = cleanStr.toLowerCase();
    let sortedReversedStr = reversedArr.join("").toLowerCase();
    return sortedstr === sortedReversedStr;
  };