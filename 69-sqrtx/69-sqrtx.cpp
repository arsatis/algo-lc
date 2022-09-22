class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int mySqrt(int x) {
        int ans;
        for (int l = 1, r = x; l <= r;) {
            int m = l + ((r - l) >> 1);
            if ((long long) m * m <= x) ans = m, l = m + 1;
            else r = m - 1;
        }
        return ans;
    }
};