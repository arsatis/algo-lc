class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
        
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> increase;
        increase.push_back(nums[0]);
        for (int num : nums) {
            if (num > increase.back()) {
                increase.push_back(num);
            } else {
                int l = 0;
                int r = increase.size() - 1;
                while (l < r) {
                    int mid = l + (r - l) / 2;
                    if (num > increase[mid]) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }
                increase[l] = num;
            }
        }
        return increase.size();
    }
};