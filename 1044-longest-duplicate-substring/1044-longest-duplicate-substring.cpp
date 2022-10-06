class Solution {
    string dupWithLength(string& s, int n) {
        unordered_map<int, int> hashes;
        int shift = 5, mod = 5e7 + 17, multiplier = 1, sHash = 0;
        
        for (int i = 1; i < n; ++i) multiplier = (multiplier << shift) % mod;
        for (int i = 0; i < n; ++i) sHash = ((sHash << shift) + s[i] - 'a') % mod;
        hashes[sHash] = n - 1;
        
        for (int i = n; i < s.size(); ++i) {
            sHash = (sHash + mod - (multiplier * (s[i - n] - 'a') % mod)) % mod; // remove leftmost element
            sHash = ((sHash << shift) + s[i] - 'a') % mod; // add rightmost element
            if (hashes.find(sHash) != hashes.end() &&
                s.substr(i - n + 1, n) == s.substr(hashes[sHash] - n + 1, n)) return s.substr(i - n + 1, n);
            hashes[sHash] = i;
        }
        return "";
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    string longestDupSubstring(string& s) {
        int lo = 0, hi = s.size() - 1;
        string maxDup = "", dup;
        while (lo < hi) {
            int mid = (lo + hi + 1) >> 1;
            if ((dup = dupWithLength(s, mid)) == "") hi = mid - 1;
            else {
                lo = mid;
                if (mid > maxDup.size()) maxDup = dup;
            }
        }
        return maxDup;
    }
};