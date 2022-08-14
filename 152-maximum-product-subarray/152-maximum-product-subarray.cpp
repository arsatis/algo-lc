class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPos = nums[0], currPos = 1, currNeg = 1;
        for (auto& n : nums) {
            if (n == 0) {
                currPos = 1;
                currNeg = 1;
                maxPos = max(maxPos, 0);
            } else if (n > 0) {
                currPos *= n;
                currNeg *= n;
                maxPos = max(maxPos, currPos);
            } else {
                if (currNeg > 0) {
                    currNeg *= n;
                    currPos = 1;
                } else {
                    int temp = currPos * n;
                    currPos = currNeg * n;
                    currNeg = temp;
                    maxPos = max(maxPos, currPos);
                }
            }
        }
        return maxPos;
    }
};