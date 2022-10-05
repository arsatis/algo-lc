class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    string longestPrefix(string& s) {
        int shift = 5, mod = 1e7 + 19, n = s.size();
        int sHash = 0, tHash;
        vector<int> multipliers(1, 1), tHashes(n);
        multipliers.reserve(n);
        
        for (int i = 1; i < n; ++i) multipliers.emplace_back((multipliers.back() << shift) % mod);
        for (int i = 0; i < n; ++i) {
            sHash = ((sHash << shift) + s[i]) % mod;
            tHashes[i] = sHash;
        }
        
        for (int i = n - 1; i > 0; --i) {
            sHash = (sHash + mod - (multipliers[i] * s[n - 1 - i] % mod)) % mod; // remove leftmost element
            tHash = tHashes[i - 1];
            if (sHash == tHash) return s.substr(0, i);
        }
        return "";
    }
};