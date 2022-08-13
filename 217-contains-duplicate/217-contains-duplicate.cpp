class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for (auto it = nums.begin(); it != nums.end(); ++it)
            if (find(nums.begin(), nums.end(), *it) != it)
                return true;
        return false;
    }
};