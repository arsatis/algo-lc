class Solution {
    int f(vector<int>& nums, int start, int end) {
        int i = 0, j = 0;
        for (int x = start; x < end; ++x) {
            int tmp = j;
            j = max(i + nums[x], j);
            i = tmp;
        }
        return j;
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(f(nums, 0, nums.size() - 1), f(nums, 1, nums.size()));
    }
};