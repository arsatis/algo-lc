class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> explored;
        for (auto &n : nums) {
            if (explored[n] > 0) return true;
            ++explored[n];
        }
        return false;
    }
};