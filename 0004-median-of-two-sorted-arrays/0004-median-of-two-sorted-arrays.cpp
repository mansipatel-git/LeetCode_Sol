class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j])
                merge.push_back(nums1[i++]);
            else
                merge.push_back(nums2[j++]);
        }

        while (i < nums1.size())
            merge.push_back(nums1[i++]);

        while (j < nums2.size())
            merge.push_back(nums2[j++]);

        int n = merge.size();

        if (n % 2 == 1)
            return merge[n / 2];
        else
            return (merge[n / 2 - 1] + merge[n / 2]) / 2.0;
    }
};