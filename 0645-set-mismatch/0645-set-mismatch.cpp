class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> output;
        output.reserve(2);
        for (int x : nums) nums[abs(x) - 1] *= -1;
        for (int i = 0; i < nums.size(); ++i) if (nums[i] > 0) output.emplace_back(i + 1);
        if (find(nums.begin(), nums.end(), output.front()) == nums.end() &&
            find(nums.begin(), nums.end(), -output.front()) == nums.end()) reverse(output.begin(), output.end());
        return move(output);
    }
};