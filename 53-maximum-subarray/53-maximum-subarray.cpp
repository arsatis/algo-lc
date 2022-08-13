class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cout.tie(0);
        cin.tie(0);

        int currSum = 0, maxSum = INT_MIN;
        for (auto& n : nums) {
            currSum += n;
            maxSum = max(maxSum, currSum);
            currSum = max(currSum, 0);
        }
        return maxSum;
    }
};