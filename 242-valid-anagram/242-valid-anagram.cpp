class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> m1(29, 0), m2(29, 0);
        for (int i = 0; i < s.size(); ++i) ++m1[s[i] - 'a'];
        for (int i = 0; i < t.size(); ++i) ++m2[t[i] - 'a'];
        return m1 == m2;
    }
};