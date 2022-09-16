class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
        int minPdt = 1, maxPdt = 1, mx = INT_MIN;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) swap(minPdt, maxPdt);
            maxPdt = max(nums[i], maxPdt * nums[i]);
            minPdt = min(nums[i], minPdt * nums[i]);
            mx = max(mx, maxPdt);
        }
        return mx;
    }
};