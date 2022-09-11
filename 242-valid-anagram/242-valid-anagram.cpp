class Solution {
public:
    bool isAnagram(string s, string t) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int chars[26] = { 0 };
        for (char c : s) ++chars[c - 'a'];
        for (char c : t) if (chars[c - 'a']-- == 0) return false;
        return !accumulate(chars, chars + 26, 0);
    }
};