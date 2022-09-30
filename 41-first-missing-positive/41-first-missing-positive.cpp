class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int firstMissingPositive(vector<int>& nums) {
        for (int& i : nums) if (i < 1) i = nums.size() + 1;
        for (int i : nums) {
            int tmp = abs(i) - 1;
            if (tmp < nums.size() && nums[tmp] > 0) nums[tmp] *= -1;
        }
        for (int i = 0; i < nums.size(); ++i) if (nums[i] > 0) return i + 1;
        return nums.size() + 1;
    }
};