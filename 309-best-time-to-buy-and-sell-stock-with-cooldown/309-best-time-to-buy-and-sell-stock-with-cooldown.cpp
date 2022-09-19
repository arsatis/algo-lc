class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int maxProfit(vector<int>& prices) {
        int cooldown = 0, sell = 0, buy = -prices[0];
        for (int i : prices) {
            int tmp = sell;
            sell = buy + i;
            buy = max(buy, cooldown - i);
            cooldown = max(cooldown, tmp);
        }
        return max(sell, cooldown);
    }
};