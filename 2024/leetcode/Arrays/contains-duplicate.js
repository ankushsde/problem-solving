let nums = [1, 2, 3, 1,3,7,8,9,8];
let n = nums.length;

const findDuplicates = (inputArray) => {
  if (!inputArray || !Array.isArray(inputArray)) {
    throw new Error("Input is not a valid array");
  }
  const uniqueSet = new Set(inputArray)
  return inputArray.length !== uniqueSet.size
};

const removeDuplicates = (arr)=>{
     let i = 0;
    let flag = 0
    let duplicates = []
    arr.sort((a,b)=>a-b)
    for(let j = i+1; j<n ; j++){
        if(arr[j] !== arr[i]){
            i++;
            arr[i] = arr[j]
            flag = 1
        } else{
            duplicates.push(arr[j])
        }
    }
    console.log(flag == 1 ? true : false)
    console.log("Duplicate elements: ", duplicates);
    return arr.slice(0,i + 1)

}

const logDuplicatesPresent = (inputArray) => {
  try {
    const hasDuplicates = findDuplicates(inputArray)
    const uniqueElements = removeDuplicates(inputArray)
    console.log(`Duplicates Present: ${hasDuplicates}`)
    console.log(`Unique Elements: ${uniqueElements}`)

    
  } catch (error) {
    console.log(`Error: ${error.message}`)
  }
}

logDuplicatesPresent(nums)
