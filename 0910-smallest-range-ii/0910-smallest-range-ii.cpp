class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mx = nums[nums.size() - 1], mn = nums[0], res = mx - mn;
        for (int i = 0; i < nums.size() - 1; ++i) {
            mx = max(mx, nums[i] + (k << 1));
            mn = min(nums[i + 1], nums[0] + (k << 1));
            res = min(res, mx - mn);
        }
        return res;
    }
};