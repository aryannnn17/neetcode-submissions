class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n - 1;
        int area = 0;
        while (l < r) {
            area = max(area, min(heights[r], heights[l]) * (r - l));
            if (heights[l] >= heights[r])
                r--;
            else
                l++;
        }
        return area;
    }
};
