class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // makes use of locality: O(nk), but faster than O(n) algorithms
        uint_least8_t size = nums.size() - 1;
        for (uint_fast8_t i = 0; i < size; ++i)
            for (uint_fast8_t j = i + 1; j - i <= k && j <= size; ++j)
                if (nums[i] == nums[j]) return true;
        return false;
    }
};