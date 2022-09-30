class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> missing;
        missing.reserve(nums.size());
        for (int i : nums) {
            int tmp = abs(i) - 1;
            if (nums[tmp] > 0) nums[tmp] *= -1;
        }
        for (int i = 0; i < nums.size(); ++i) if (nums[i] > 0) missing.emplace_back(i + 1);
        return move(missing);
    }
};