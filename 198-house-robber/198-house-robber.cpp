class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int rob(vector<int>& nums) {
        int prev2 = 0, prev1 = 0;
        for (int i : nums) {
            prev2 = max(prev2 + i, prev1);
            swap(prev2, prev1);
        }
        return prev1;
    }
};