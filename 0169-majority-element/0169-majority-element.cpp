class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int t = n >> 1;
        sort(nums.begin() , nums.end());
        return nums[t];
    }
};