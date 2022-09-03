class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
        vector<int> increase = { nums[0] };
        
        for (int num : nums) {
            if (num > increase.back()) increase.push_back(num);
            else {
                auto it = lower_bound(increase.begin(), increase.end(), num);
                *it = num;
            }
        }
        return increase.size();
    }
};