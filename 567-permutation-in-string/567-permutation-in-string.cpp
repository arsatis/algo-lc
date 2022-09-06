class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int chars[26] = { 0 };
        for (char& c : s1) ++chars[c - 'a'];
        for (int l = 0, r = 0; r < s2.size(); ++r) {
            while (chars[s2[r] - 'a'] == 0) ++chars[s2[l++] - 'a'];
            if (r - l + 1 == s1.size()) return true;
            --chars[s2[r] - 'a'];
        }
        return false;
    }
};