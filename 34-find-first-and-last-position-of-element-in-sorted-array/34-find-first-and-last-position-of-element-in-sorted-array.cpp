class Solution {
public:
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