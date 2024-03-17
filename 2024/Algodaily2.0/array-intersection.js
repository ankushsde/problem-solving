let nums1 = [4,9,5];
let nums2 = [9,4,9,8,4];

function intersection(num1,num2){
    num1 = nums1.sort()
    nums2 = nums2.sort()
    let ans = []
    let i = 0;
    let j = 0;
    while(i<nums1.length && j < nums2.length){
        if(nums1[i]<nums2[j]){
            i++
        }
        else if( nums2[j] < nums1[i]){
            j++
        }
        else {
            ans.push(nums1[i]);
            i++
            j++
        }
    }
    
        ans = Array.from(new Set(ans));
    return ans
}



console.log(intersection(nums1, nums2));

//TC: sorting : O(nlogn) , intersection : O(n+m), set : O(k)