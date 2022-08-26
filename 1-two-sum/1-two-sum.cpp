class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        unordered_map<int, int> comp;
        vector<int> vi;
        for (int i = 0; i < nums.size(); ++i) {
            if (comp.find(target - nums[i]) != comp.end()) {
                vi.push_back(i);
                vi.push_back(comp[target - nums[i]]);
                return vi;
            }
            comp[nums[i]] = i;
        }
        return vi;
    }
};