function lonelyNumber(nums) {
    //XOR Way
    // let result = 0 ;
    // for(let i = 0; i<nums.length;i++){
    //     result = result ^ nums[i]
    // }
    // return result;

    //Set way 

    let newSet = new Set();
     for (let i = 0; i<nums.length;i++){
        let num = nums[i]
        if(newSet.has(num)){
            newSet.delete(num)
                 } else {
            newSet.add(num)
        }
    }
    return arr;
}

 
console.log(lonelyNumber([4, 4, 6, 1, 3, 1, 3]));  // Output: 6
console.log(lonelyNumber([3, 3, 9]));                // Output: 9
