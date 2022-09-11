class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        unordered_set<int> seen;
        for (int& i : nums) {
            if (seen.find(i) != seen.end()) return true;
            seen.insert(i);
        }
        return false;
    }
};