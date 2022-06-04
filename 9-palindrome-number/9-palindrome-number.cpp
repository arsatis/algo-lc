class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int divisor = 1;
        int leading, trailing;
        while (x / divisor >= 10) divisor *= 10;
        while (x != 0) {
          leading = x / divisor;
            trailing = x % 10;
            if (leading != trailing) return false;
            x = (x % divisor) / 10;
            divisor = divisor / 100;
        }
        return true;
    }
};