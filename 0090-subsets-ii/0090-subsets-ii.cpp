class Solution {
    vector<vector<int>> output;
    void f(vector<int>& nums, vector<int>& subset, int idx) {
        output.emplace_back(subset);
        for (int i = idx; i < nums.size(); ++i) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            subset.emplace_back(nums[i]);
            f(nums, subset, i + 1);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        f(nums, subset, 0);
        return move(output);
    }
};
