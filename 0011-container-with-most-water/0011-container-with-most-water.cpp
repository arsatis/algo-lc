class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx = 0;
        for (int l = 0, r = height.size() - 1; l < r;) {
            mx = max(mx, min(height[l], height[r]) * (r - l));
            if (height[r] > height[l]) ++l;
            else --r;
        }
        return mx;
    }
};
