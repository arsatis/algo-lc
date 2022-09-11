class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n = cost.size();
        for (int i = 2; i < n; ++i) cost[i] += min(cost[i - 1], cost[i - 2]); 
        return min(cost[n - 1], cost[n - 2]);
    }
};