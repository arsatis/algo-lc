class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
        vector<int> increase = { nums[0] };
        
        for (int num : nums) {
            if (num > increase.back()) increase.push_back(num);
            else {
                int l = 0, r = increase.size() - 1;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (num > increase[mid]) l = mid + 1;
                    else r = mid;
                }
                increase[l] = num;
            }
        }
        return increase.size();
    }
};