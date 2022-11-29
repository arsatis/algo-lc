class Solution {
public:
    bool isValidPalindrome(string& s, int k) {
        int temp, prev, memo[1000] = {};
        for (int i = s.size() - 2; i >= 0; --i) {
            prev = 0;
            for (int j = i + 1; j < s.size(); ++j) {
                temp = memo[j];
                if (s[i] == s[j]) memo[j] = prev;
                else memo[j] = 1 + min(memo[j], memo[j - 1]);
                prev = temp;
            }
        }
        return memo[s.size() - 1] <= k;
    }
};
