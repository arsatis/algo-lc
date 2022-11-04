class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = nums.size(), total = 0;
        for (int l = 0, r = 0; r < nums.size();) {
            total += nums[r++];
            while (total - nums[l] >= target) total -= nums[l++];
            if (total >= target) minLen = min(minLen, r - l);
        }
        return total >= target ? minLen : 0;
    }
};
