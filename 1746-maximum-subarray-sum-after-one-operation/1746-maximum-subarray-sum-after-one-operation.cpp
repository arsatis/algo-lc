class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int sq = 0, no_sq = 0, res = 0;
        for (int x : nums) {
            sq = max(sq + x, no_sq + x * x);
            no_sq = max(0, x + no_sq);
            res = max(res, sq);
        }
        return res;
    }
};
