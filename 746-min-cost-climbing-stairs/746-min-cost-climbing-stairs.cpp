class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() < 2) return 0;
        int prev2 = 0, prev1 = 0;
        for (int i = 2; i < cost.size() + 1; ++i) {
            prev2 = min(prev2 + cost[i - 2], prev1 + cost[i - 1]);
            swap(prev2, prev1);
        }
        return prev1;
    }
};