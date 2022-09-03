class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> increase;
        increase.push_back(nums[0]);
        
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