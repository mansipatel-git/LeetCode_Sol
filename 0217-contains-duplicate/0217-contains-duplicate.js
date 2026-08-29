/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    let s = new Set();

    for(let x of nums){
        if(s.has(x)){
            return true;
        }
        s.add(x);
    }
    return false;
};