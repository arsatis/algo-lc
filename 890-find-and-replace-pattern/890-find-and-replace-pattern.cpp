class Solution {
public:
    vector<string> findAndReplacePattern(vector<string> &words, string p) {
        ios_base::sync_with_stdio(false);
        vector<string> res;
        string s = F(p);
        for (string &w : words) if (F(w) == s) res.push_back(w);
        return res;
    }

    string F(string w) {
        unordered_map<char, int> m;
        for (char c : w) if (!m.count(c)) m[c] = m.size();
        for (int i = 0; i < w.length(); ++i) w[i] = 'a' + m[w[i]];
        return w;
    }
};