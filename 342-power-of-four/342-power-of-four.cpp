class Solution {
public:
    bool isPowerOfFour(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        if (n < 1) return false;
        while (n != 1) {
            if (n % 4 != 0) return false;
            n >>= 2;
        }
        return true;
    }
};