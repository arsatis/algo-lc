class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int trap(vector<int>& height) {
        int total = 0, leftMax = 0, rightMax = 0;
        
        for (int left = 0, right = height.size() - 1; left < right;) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) leftMax = height[left++];
                else total += leftMax - height[left++];
            } else {
                if (height[right] >= rightMax) rightMax = height[right--];
                else total += rightMax - height[right--];
            }
        }
        return total;
    }
};