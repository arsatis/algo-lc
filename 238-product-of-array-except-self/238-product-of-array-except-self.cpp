class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<int> ans(nums.size(), 1);
        int temp = 1;
        for (int i = 1; i < nums.size(); ++i) ans[i] = ans[i - 1] * nums[i - 1];
        for (int i = nums.size() - 2; i >= 0; --i) {
            temp *= nums[i + 1];
            ans[i] *= temp;
        }
        return ans;
    }
};