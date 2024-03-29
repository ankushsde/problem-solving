
var subsets = function (nums) {
    let sets = [];

    if (nums.length === 0) {
        return [[]];
    } else {
        let subsetsCount = 2 ** nums.length;
        for (let i = 0; i < subsetsCount; i++) {

            let subset = new Set();
            for (let j = 0; j < nums.length; j++) {
                if (getBit(i, j) == 1 && !subset.has(nums[j])) {
                    subset.add(nums[j]);
                }
            }

            if (i === 0) {
                sets.push([]);
            } else {
                sets.push(Array.from(subset));
            }

        }
    }
    return sets;
};

function getBit(num, bit) {
    let temp;
    temp = 1 << bit;
    temp = temp & num;

    if (temp === 0) {
        return 0;
    }

    return 1;
}