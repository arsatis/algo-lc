class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int concatenatedBinary(int n) {
        long ret = 1;
        int len = 1;
        for (int i = 2; i <= n; ++i) {
            if ((i & (i - 1)) == 0) ++len;
            ret = (ret << len) % 1000000007 + i;
        }
        return ret % 1000000007;
    }
};