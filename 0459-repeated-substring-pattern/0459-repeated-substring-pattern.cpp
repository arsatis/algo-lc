class Solution {
    bool rabinKarp(string& s, string& t) { // s: source (longer string), t: target (shorter string)
        int shift = 5, mod = 1e7 + 19, multiplier = 1, n = t.size();
        int sHash = 0, tHash = 0;
        
        for (int i = 1; i < n; ++i) multiplier = (multiplier << shift) % mod;
        for (int i = 0; i < n; ++i) {
            sHash = ((sHash << shift) + s[i] - 'a') % mod;
            tHash = ((tHash << shift) + t[i] - 'a') % mod;
        }
        
        if (sHash == tHash) return true;
        for (int i = n; i < s.size(); ++i) {
            sHash = (sHash + mod - (multiplier * (s[i - n] - 'a') % mod)) % mod; // remove leftmost element
            sHash = ((sHash << shift) + s[i] - 'a') % mod; // add rightmost element
            if (sHash == tHash) return true;
        }
        return false;
    }
public:
    bool repeatedSubstringPattern(string s) {
        string s2 = (s + s).substr(1, s.size() - 1 << 1);
        return rabinKarp(s2, s);
    }
};