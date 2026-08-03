class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>merge;
        int i = 0;
        int j = 0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                merge.push_back(nums1[i]);
                i++;
            }else{
                merge.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m){
            merge.push_back(nums1[i]);
            i++;
        }
        while(j < n ){
            merge.push_back(nums2[j]);
            j++;
        }


        // 
        for(int i =0; i < n+ m ; i++){
            nums1[i] = merge[i];
        }
    }
};