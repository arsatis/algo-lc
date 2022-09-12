class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        if (cost.size() < 2) return 0;
        int i = 0, j = 0;
        for (int x = 2; x < cost.size() + 1; ++x) {
            i = min(i + cost[x - 2], j + cost[x - 1]);
            swap(i, j);
        }
        return j;
    }
};