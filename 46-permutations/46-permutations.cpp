class Solution {
    void f(vector<vector<int>>& perms, vector<int>& nums, int begin) {
		if (begin >= nums.size()) perms.push_back(nums);
		else {
            for (int i = begin; i < nums.size(); ++i) {
                swap(nums[begin], nums[i]);
                f(perms, nums, begin + 1);
                swap(nums[begin], nums[i]);
            }
		}
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        
	    vector<vector<int>> perms;
	    f(perms, nums, 0);
	    return perms;
    }
};