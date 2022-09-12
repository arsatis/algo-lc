class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        int i = nums[0], j = nums[1], k = nums[0] + nums[2];
        for (int x = 3; x < nums.size(); ++x) {
            i = max(i, j) + nums[x];
            swap(i, k);
            swap(i, j);
        }
        return max(j, k);
    }
};