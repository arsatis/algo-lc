class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0, j = 0, k = 0; k < nums.size(); ++k) {
            if (nums[k] == 1) swap(nums[k], nums[j++]);
            else if (nums[k] == 0) {
                swap(nums[k], nums[j]);
                if (i != j) swap(nums[i], nums[j]);
                ++i, ++j;
            }
        }
    }
};
