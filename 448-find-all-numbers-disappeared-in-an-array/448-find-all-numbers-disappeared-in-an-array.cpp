class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> missing;
        for (int i : nums) if (nums[abs(i) - 1] > 0) nums[abs(i) - 1] *= -1;
        for (int i = 0; i < nums.size(); ++i) if (nums[i] > 0) missing.emplace_back(i + 1);
        return move(missing);
    }
};