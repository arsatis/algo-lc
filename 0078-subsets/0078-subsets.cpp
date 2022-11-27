class Solution {
    vector<vector<int>> output;
    void f(vector<int>& nums, vector<int>& subset, int idx) {
        output.emplace_back(subset);
        for (int i = idx; i < nums.size(); ++i) {
            subset.emplace_back(nums[i]);
            f(nums, subset, i + 1);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        f(nums, subset, 0);
        return move(output);
    }
};
