class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> sold(k), bought(k, INT_MIN);
        for (int x : prices) {
            for (int i = 0; i < k; ++i) {
                bought[i] = max(bought[i], (i == 0 ? 0 : sold[i - 1]) - x);
                sold[i] = max(sold[i], bought[i] + x);
            }
        }
        return *max_element(sold.begin(), sold.end());
    }
};
