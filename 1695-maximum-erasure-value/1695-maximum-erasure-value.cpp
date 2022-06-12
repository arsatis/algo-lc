class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> si;
        int l = 0, r = 0, output = 0, currSum = 0;
        while (r < nums.size()) {
            while (si.find(nums[r]) != si.end()) {
                si.erase(nums[l]);
                currSum -= nums[l];
                ++l;
            }
            si.insert(nums[r]);
            currSum += nums[r];
            output = max(output, currSum);
            ++r;
        }
        return output;
    }
};