class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int strStr(string haystack, string needle) {
        int shift = 5, mod = 1e7 + 19, multiplier = 1, n = needle.size();
        long nHash = 0, hHash = 0;
        
        for (int i = 1; i < n; ++i) multiplier = (multiplier << shift) % mod;
        for (int i = 0; i < n; ++i) {
            nHash = ((nHash << shift) + needle[i] - '`') % mod;
            hHash = ((hHash << shift) + haystack[i] - '`') % mod;
        }
        
        if (hHash == nHash) return 0;
        for (int i = n; i < haystack.size(); ++i) {
            hHash = (hHash + mod - (multiplier * (haystack[i - n] - '`') % mod)) % mod; // remove leftmost element
            hHash = ((hHash << shift) + haystack[i] - '`') % mod; // add rightmost element
            if (hHash == nHash) return i - n + 1;
        }
        return -1;
    }
};