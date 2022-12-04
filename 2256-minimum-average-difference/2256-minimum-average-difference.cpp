class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size(), minIdx = 0;
        long curr = 0, total = accumulate(nums.begin(), nums.end(), (long) 0), minDiff = total;
        for (int i = 1; i <= n; ++i) {
            curr += nums[i - 1];
            long tmp = i == n ? total / n : abs(curr / i - (total - curr) / (n - i));
            if (minDiff > tmp) minDiff = tmp, minIdx = i - 1;
        }
        return minIdx;
    }
};
