class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int maxProfit = 0, minPrice = INT_MAX;
        for (auto& p : prices) {
            if (p < minPrice) minPrice = p;
            else maxProfit = max(maxProfit, p - minPrice);
        }
        return maxProfit;
    }
};