let nums =[0,0,0,0]

let findMinEven = (nums) =>{
    let n = nums.length
    
    let evenArr = []
    
    for(let i = 0; i<n; i++){
        if(nums[i] % 2 === 0 && nums[i] != 0){
            evenArr.push(nums[i])
        }
    }
    
    let smallest = evenArr[0]
        for (let i = 1; i < evenArr.length ; i++){
            if(evenArr[i]<smallest){
                smallest = evenArr[i]
            }
        }
    
    evenArr.sort((a,b)=>a-b)
    let count = -1
    let max = 0
    let number 
    
    for(let i = 0; i< evenArr.length;i++){
        if(evenArr[i] === evenArr[i-1]){
            count++
        } else {
            count = 1
        }
        
        if(count > max){
            max = count 
            number = evenArr[i]
        }
    }
    
    return number ? number : -1
}
console.log(findMinEven(nums))