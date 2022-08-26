class Solution {
public:
    int jump(vector<int>& nums) {
        int ci = nums[0], mi = nums[0], cnt = 0;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (i > ci) {
                ci = mi;
                ++cnt;
            }
            if (ci >= nums.size() - 1) {
                ++cnt;
                break;
            }
            mi = max(mi, nums[i] + i);
        }
        return cnt;
    }
};