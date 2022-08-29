class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int ans = 0;
        for (auto& x : nums) ans ^= x;
        return ans;
    }
};