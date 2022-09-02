class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sMap[128] = { 0 }, tMap[128] = { 0 };
        for (int i = 0; i < s.size(); ++i) {
            if (!sMap[s[i]] && !tMap[t[i]]) {
                sMap[s[i]] = t[i];
                tMap[t[i]] = s[i];
            } else if (sMap[s[i]] != t[i] || tMap[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};