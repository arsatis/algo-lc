class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> m1(256, 0), m2(256, 0);
        int m = s.length();
        int n = t.length();
        for (int i = 0; i < m; ++i) ++m1[s[i]];
        for (int i = 0; i < n; ++i) ++m2[t[i]];
        return m1 == m2;
    }
};