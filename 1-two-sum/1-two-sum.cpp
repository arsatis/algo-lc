class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diff;
        vector<int> output;
        for (int i = 0; i < nums.size(); ++i) {
            if (diff.count(target - nums[i]) == 0) diff[nums[i]] = i;
            else {
                output.push_back(diff[target - nums[i]]);
                output.push_back(i);
                break;
            }
        }
        return output;
    }
};