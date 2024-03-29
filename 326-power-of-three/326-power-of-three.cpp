class Solution {
public:
    bool isPowerOfThree(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        if (n < 1) return false;
        else if (n > 100000) return 1162261467 % n == 0;
        while (n != 1) {
            if (n % 3 != 0) return false;
            n /= 3;
        }
        return true;
    }
};