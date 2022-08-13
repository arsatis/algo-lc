class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> m1(256, 0), m2(256, 0);
        for (int i = 0; i < s.size(); ++i) ++m1[s[i]];
        for (int i = 0; i < t.size(); ++i) ++m2[t[i]];
        return m1 == m2;
    }
};