class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> increase = { nums[0] };
        for (int num : nums) {
            if (num > increase.back()) increase.push_back(num);
            else *lower_bound(increase.begin(), increase.end(), num) = num;
        }
        return increase.size();
    }
};