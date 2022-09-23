class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lo = lower_bound(nums.begin(), nums.end(), target),
             hi = upper_bound(nums.begin(), nums.end(), target);
        if (nums.size() == 0 || lo == nums.end() || *lo != target) return { -1, -1 };
        else {
            int a = lo - nums.begin(), b = hi - nums.begin() - 1;
            return { a, b };
        }
    }
};