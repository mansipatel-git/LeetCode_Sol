class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2 ; i++){
            int l = i+1;
            int r = n-1;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    result.push_back({nums[i] , nums[l], nums[r]});
                    l++;
                    r--;
                    
                    while (l < r && nums[l] == nums[l - 1])
                        l++;

                    // Skip duplicate third element
                    while (l < r && nums[r] == nums[r + 1])
                        r--;

                }else if (sum < 0) {
                    l++;
                }
                else {
                    r--;
                }

                
            }
        }
        return result;
    }
};