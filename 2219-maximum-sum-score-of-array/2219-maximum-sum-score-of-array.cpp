class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), (long long) 0),
                  prefixSum = 0, maxSum = LLONG_MIN;
        for (int i : nums) {
            maxSum = max(maxSum, sum - prefixSum);
            prefixSum += i;
            maxSum = max(maxSum, prefixSum);
        }
        return maxSum;
    }
};