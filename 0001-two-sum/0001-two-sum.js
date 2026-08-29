/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {

    let v = [];

    // Store [value, original index]
    for (let i = 0; i < nums.length; i++) {
        v.push([nums[i], i]);
    }

    // Sort by value
    v.sort((a, b) => a[0] - b[0]);

    let l = 0;
    let r = nums.length - 1;

    while (l < r) {

        let sum = v[l][0] + v[r][0];

        if (sum === target) {
            return [v[l][1], v[r][1]];
        }
        else if (sum < target) {
            l++;
        }
        else {
            r--;
        }
    }

    return [];
};