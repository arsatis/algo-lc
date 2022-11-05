class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold[2] = {}, bought[2] = {INT_MIN, INT_MIN};
        for (int x : prices) {
            bought[0] = max(bought[0], -x);
            sold[0] = max(sold[0], bought[0] + x);
            bought[1] = max(bought[1], sold[0] - x);
            sold[1] = max(sold[1], bought[1] + x);
        }
        return max(sold[0], sold[1]);
    }
};
