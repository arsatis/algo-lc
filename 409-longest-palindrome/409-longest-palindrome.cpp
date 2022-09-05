class Solution {
public:
    int longestPalindrome(string s) {
        ios_base::sync_with_stdio(0);
        
        int len = 0, chars[64] = { 0 };
        for (char c : s) if (++chars[c - 'A'] % 2 == 0) len += 2;
        for (int i : chars) if (i % 2 == 1) return 1 + len;
        return len;
    }
};