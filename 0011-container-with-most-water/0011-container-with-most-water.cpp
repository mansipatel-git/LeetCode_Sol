class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int Maxarea = 0;
        while(l < r){
            int w = r - l;
            int h = min(height[l] , height[r]);
            int area  = w * h;
            Maxarea = max(Maxarea, area);
            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }

        }
        return Maxarea;

    }
};