class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        unordered_map<int, int> comp;
        for (int i = 0; i < nums.size(); ++i) {
            if (comp.find(nums[i]) != comp.end()) return { i, comp[nums[i]] };
            comp[target - nums[i]] = i;
        }
        return {};
    }
};