class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxNum = 0, zero = -1, left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                maxNum = max(maxNum, right - left);
                if (zero != -1) left = zero + 1;
                zero = right;
            }
        }
        maxNum = max(maxNum, (int) nums.size() - left);
        return zero == -1 ? nums.size() : maxNum;
    }
};