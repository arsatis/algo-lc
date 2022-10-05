class Solution {
    bool rabinKarp(string& s, string& t) { // s: source (longer string), t: target (shorter string)
        int shift = 5, mod = 1e7 + 19, multiplier = 1, n = t.size();
        int sHash = 0, tHash = 0;
        
        for (int i = 1; i < n; ++i) multiplier = (multiplier << shift) % mod;
        for (int i = 0; i < n; ++i) {
            sHash = ((sHash << shift) + s[i]) % mod;
            tHash = ((tHash << shift) + t[i]) % mod;
        }
        
        if (sHash == tHash) return true;
        for (int i = n; i < s.size(); ++i) {
            sHash = (sHash + mod - (multiplier * s[i - n] % mod)) % mod; // remove leftmost element
            sHash = ((sHash << shift) + s[i]) % mod; // add rightmost element
            if (sHash == tHash) return true;
        }
        return false;
    }
public:
    int repeatedStringMatch(string& a, string& b) {
        int count = 0;
        string s = "";
        while (s.size() < b.size()) s += a, ++count;
        
        if (rabinKarp(s, b)) return count;
        if (rabinKarp(s += a, b)) return count + 1;
        return -1;
    }
};