class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(0);
        
        int maxProfit = 0, minPrice = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < prices[i - 1]) {
                maxProfit += prices[i - 1] - minPrice;
                minPrice = prices[i];
            }
        }
        return maxProfit + prices.back() - minPrice;
    }
};