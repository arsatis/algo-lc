class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int sell = 0, buy = INT_MIN; 
        for (int i : prices) {
            int tmp = sell;
            sell = max(sell, buy + i);
            buy = max(buy, tmp - i - fee);
        }
        return sell;
    }
};