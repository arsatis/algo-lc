class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(0);
        
        int left = 0, right = height.size() - 1, mx = 0;
        while (left < right) {
            mx = max(mx, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) ++left;
            else --right;
        }
        return mx;
    }
};