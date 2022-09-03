class Solution {
public:
    int climbStairs(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        if (n <= 2) return n;
        int x = 1, y = 2;
        for (int i = 3; i <= n; ++i) {
            swap(x += y, y);
        }
        return y;
    }
};