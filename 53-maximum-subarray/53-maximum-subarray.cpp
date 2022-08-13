class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;
        
        for (auto& n : nums) {
            currSum += n;
            maxSum = max(maxSum, currSum);
            currSum = max(currSum, 0);
        }
        return maxSum;
    }
};