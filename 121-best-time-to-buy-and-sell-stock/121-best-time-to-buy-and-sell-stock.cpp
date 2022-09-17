class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minPrice = INT_MAX;
        for (auto& p : prices) {
            if (p < minPrice) minPrice = p;
            else maxProfit = max(maxProfit, p - minPrice);
        }
        return maxProfit;
    }
};