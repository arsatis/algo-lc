class Solution {
public:
    int jump(vector<int>& nums) {
        int ci = nums[0], mi = nums[0], count = 0;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (i > ci) {
                ++count;
                ci = mi;
            }
            if (ci >= nums.size() - 1) {
                ++count;
                break;
            }
            mi = max(mi, nums[i] + i);
        }
        return count;
    }
};