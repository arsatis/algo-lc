class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPos = nums[0], currPos = -20, currNeg = 20;
        for (auto& n : nums) {
            int newPos, newNeg;
            if (n < 0) {
                newPos = max(n, n * currNeg);
                newNeg = min(n, n * currPos);
            } else {
                newPos = max(n, n * currPos);
                newNeg = min(n, n * currNeg);
            }
            currPos = newPos;
            currNeg = newNeg;
            maxPos = max(maxPos, currPos);
        }
        return maxPos;
    }
};