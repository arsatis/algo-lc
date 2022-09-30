class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
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