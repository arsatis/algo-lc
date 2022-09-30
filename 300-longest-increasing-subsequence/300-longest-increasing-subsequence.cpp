class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> increase = { nums[0] };
        for (int num : nums) {
            if (num > increase.back()) increase.push_back(num);
            else *lower_bound(increase.begin(), increase.end(), num) = num;
        }
        return increase.size();
    }
};