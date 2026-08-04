class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin() , nums.end());
        vector<int>arr;
        for(int i = minVal + 1 ; i < maxVal ; i++){
            if (find(nums.begin(), nums.end(), i) == nums.end()) {
                arr.push_back(i);
            }
        }
        return arr;
    }
};