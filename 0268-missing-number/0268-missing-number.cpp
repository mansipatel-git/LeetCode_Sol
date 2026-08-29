class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Arrsum = 0;
        for(int x : nums){
            Arrsum += x;

        }
        int n = nums.size();

        int sum = (n * (n+1))>>1;

        return sum - Arrsum;

    }
};