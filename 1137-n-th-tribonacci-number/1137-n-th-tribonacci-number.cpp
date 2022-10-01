class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int tribonacci(int n) {
        if (n <= 1) return n;
        int prev3 = 0, prev2 = 1, prev1 = 1;
        while (n-- > 2) {
            swap(prev3 += (prev2 + prev1), prev1);
            swap(prev3, prev2);
        }
        return prev1;
    }
};