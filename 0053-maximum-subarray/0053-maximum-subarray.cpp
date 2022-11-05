class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = -10001, curr = 0;
        for (int x : nums) {
            curr = max(x, curr + x);
            mx = max(mx, curr);
        }
        return mx;
    }
};
