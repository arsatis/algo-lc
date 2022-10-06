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
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    bool repeatedSubstringPattern(string s) {
   		for (size_t i = 1; i < s.size(); i++) {
			if (s[i] != s[0]) continue;
			if (s.size() % i != 0) continue;
			if (s[s.size() - 1] != s[i - 1]) continue;

			int j = i, ii = 0;
			while (j < s.size()) {
				if (s[j++] != s[ii++]) break;
				if (ii == i) ii = 0;
			}

			if (j == s.size()) return true;
		}

		return false;
    }
};