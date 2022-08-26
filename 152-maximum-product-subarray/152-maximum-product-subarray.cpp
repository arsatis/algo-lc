class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0], maxProd = ans, minProd = ans;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) swap(maxProd, minProd);
            maxProd = max(nums[i], nums[i] * maxProd);
            minProd = min(nums[i], nums[i] * minProd);
            ans = max(ans, maxProd);
        }
        return ans;
    }
};