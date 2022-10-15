class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int maxProduct(vector<int>& nums) {
        int minPdt = nums[0], maxPdt = nums[0], mx = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) swap(minPdt, maxPdt);
            maxPdt = max(nums[i], maxPdt * nums[i]);
            minPdt = min(nums[i], minPdt * nums[i]);
            mx = max(mx, maxPdt);
        }
        return mx;
    }
};