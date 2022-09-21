class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int l = 0, r = 46340; l <= r;) {
            int m = (l + r) >> 1, sq = m * m;
            if (sq == num) return true;
            else if (sq < num) l = m + 1;
            else r = m - 1;
        }
        return false;
    }
};