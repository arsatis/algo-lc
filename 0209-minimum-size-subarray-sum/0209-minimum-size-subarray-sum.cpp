class Solution {
public:
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
