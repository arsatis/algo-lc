class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;
        for (int left = 0, right = 0; right < nums.size(); ++right) {
            if (right > k) seen.erase(nums[left++]);
            if (seen.find(nums[right]) != seen.end()) return true;
            seen.insert(nums[right]);
        }
        return false;
    }
};