class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        unordered_map<int, int> explored;
        for (auto &n : nums) {
            if (explored[n] > 0) return true;
            ++explored[n];
        }
        return false;
    }
};