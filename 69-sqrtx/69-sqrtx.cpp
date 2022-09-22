class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int mySqrt(int x) {
        int low = 1, high = x, mid, ans;
        while (low <= high) {
            mid = low + ((high - low) >> 1);
            if ((long long) mid * mid <= x) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};