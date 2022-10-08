class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = INT_MAX >> 2, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] + nums[n - 2] + nums[n - 1] < target) {
                int sum = nums[i] + nums[n - 2] + nums[n - 1];
                if (abs(target - sum) <  abs(target - closest)) closest = sum;
                continue;
            }
            if (nums[i] + nums[i + 1] + nums[i + 2] > target) {
                int sum = nums[i] + nums[i + 1] + nums[i + 2];
                if (abs(target - sum) <  abs(target - closest)) closest = sum;
                return closest;
            }
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    ++j;
                    continue;
                }
                if (k < n - 1 && nums[k] == nums[k + 1]) {
                    --k;
                    continue;
                }
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) return target;
                if (abs(target - sum) <  abs(target - closest)) closest = sum;
                if (sum < target) ++j;
                if (sum > target) --k;
            }
        }
        return closest;
    }
};