class Solution {
public:
    string orderlyQueue(string& s, int k) {
        if (k > 1) sort(s.begin(), s.end());
        else {
            string s2 = s + s;
            for (int i = 1; i < s.size(); ++i)
                s = min(s, s2.substr(i, s.size()));
        }
        return s;
    }
};
