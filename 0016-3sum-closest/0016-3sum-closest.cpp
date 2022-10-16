class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), closest = 0, diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            for (int left = i + 1, right = n - 1; left < right;) {
                int curr = nums[i] + nums[left] + nums[right];
                if (abs(target - curr) < diff) {
                    closest = curr;
                    diff = abs(target - curr);
                }
                if (curr == target) return curr;
                else if (curr < target) ++left;
                else --right;
            }
        }
        return closest;
    }
};