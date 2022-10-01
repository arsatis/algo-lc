class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int rob(vector<int>& nums) {
        int prev2 = 0, prev1 = 0;
        for (int i : nums) {
            int curr = max(prev2 + i, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};