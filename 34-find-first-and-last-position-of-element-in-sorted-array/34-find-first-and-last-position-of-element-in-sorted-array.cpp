class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if (!binary_search(nums.begin(),nums.end(),target)) return { -1, -1 };
        int l = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int h = upper_bound(nums.begin(),nums.end(),target) - nums.begin() - 1;
        return { l, h };
    }
};