class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int num = 0, curr = 1;
        for (int left = 0, right = 0; right < nums.size();) {
            curr *= nums[right++];
            while (left < right && curr >= k) curr /= nums[left++];
            num += (right - left);
        }
        return num;
    }
};