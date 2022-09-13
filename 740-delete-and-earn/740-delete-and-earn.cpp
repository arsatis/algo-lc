class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
        sort(nums.begin(), nums.end());
        int max_earned = 0, current_sum = nums[0];
        pair<int, int> earned_vm1{0, 0}, earned_vm2{0, 0};
        
        for (int i = 1; i <= nums.size(); ++i) {
            int v = nums[i - 1];
            if ((i < nums.size()) && (v == nums[i])) {
                current_sum += nums[i];
                continue;
            }
            int earned_v = max(current_sum + earned_vm2.second, earned_vm1.second);
            if (max_earned < earned_v) max_earned = earned_v;
            if (i < nums.size()) {
                int v_new = nums[i];
                current_sum = v_new;
                if (v == v_new - 1) earned_vm2 = earned_vm1;
                else earned_vm2 = { v, earned_v };
                earned_vm1 = { v, earned_v };
            }
        }
        return max_earned;
    }
};