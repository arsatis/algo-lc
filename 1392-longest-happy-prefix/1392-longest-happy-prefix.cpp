class Solution {
public:
    string longestPrefix(string& s) {
        long long l = 0, r = 0, p = 1, mod = 1e9 + 7;
        int k = 0;
        int n = s.length();
        for(int i = 0; i < s.size() - 1; ++i) {
            l = ((l << 7) + (s[i] - 'a')) % mod;
            r = (r + p * (s[n - 1 - i] - 'a')) % mod;
            p = (p << 7) % mod;
            if (l == r) k = i + 1;
        }
        return s.substr(0, k);
    }
};