class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        int left = 0, right = 0;
        while (l < r) {
            if (height[l]<height[r]) {
                if(left<height[l]) left = height[l++];
                else ans += left - height[l++];
            } else {
                if(right<height[r]) right = height[r--];
                else ans += right - height[r--];
            }
        }
        return ans;
    }
};