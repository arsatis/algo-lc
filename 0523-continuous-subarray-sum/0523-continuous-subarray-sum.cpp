class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen{{0, 0}};
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (!seen.count(sum % k)) seen[sum % k] = i + 1;
            else if (seen[sum % k] < i) return true;
        }
        return false;
    }
};