#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mi;
        vector<int> vi;
        for (int i = 0; i < nums.size(); i++) {
            if (mi.find(target - nums[i]) != mi.end()) {
                vi.push_back(i);
                vi.push_back(mi[target - nums[i]]);
                return vi;
            }
            mi[nums[i]] = i;
        }
        return vi;
    }
};