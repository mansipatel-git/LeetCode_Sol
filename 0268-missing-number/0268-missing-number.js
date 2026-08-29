/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    let n = nums.length ;
    let ExpSum = (n * (n+1)) / 2;
    let sum  = 0;
    for(let x of nums){
        sum += x;
    }

    return ExpSum - sum ;

};