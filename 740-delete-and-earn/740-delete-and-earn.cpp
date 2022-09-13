class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // sort the input in ascending order
        sort(nums.begin(), nums.end());
        
        // given sorted nums, solve sub-problem earned(nums, v)
        // where v is the largest value that can be taken from nums
        // start from the smalled value, cache the results as we move up the chain
        int max_earned = 0;
        
        // only need to cache the last two solutions (v, max_earned)
        std::pair<int, int> earned_vm2{0, 0};
        std::pair<int, int> earned_vm1{0, 0};
        int current_sum = nums[0];
        
        for (int j = 1; j <= nums.size(); ++j) {
            const auto& v = nums[j-1];
            if ((j < nums.size()) && (v == nums[j])) {
                current_sum += nums[j];
                continue;
            }
            // decide to take v or v-1
            // - take v: earned[v-2] + sum(v), as v-1 is cleared
            // - take v-1: earned[v-1]
            const auto earned_v = max(current_sum + earned_vm2.second, earned_vm1.second);
            //cout << v << ":" << earned_v << endl;        
            if (max_earned < earned_v) max_earned = earned_v;
            if (j < nums.size()) {
                const auto& v_new = nums[j];
                current_sum = v_new;
                if (v == v_new - 1) earned_vm2 = earned_vm1;
                else earned_vm2 = std::make_pair(v, earned_v);
                earned_vm1 = std::make_pair(v, earned_v);
            }
        }
        return max_earned;
    }
};