class Solution {
    void f(vector<string>& perms, string& s, int begin) {
        for (int i = begin; i < s.size(); ++i) {
            if (s[i] > 64 && s[i] < 91) {
                s[i] += 32;
                f(perms, s, i + 1);
                s[i] -= 32;
            }
            if (s[i] > 96 && s[i] < 123) {
                s[i] -= 32;
                f(perms, s, i + 1);
                s[i] += 32;
            }
        }
        perms.push_back(s);
    }
public:
    vector<string> letterCasePermutation(string s) {
        ios_base::sync_with_stdio(0);
        
        vector<string> perms;
        f(perms, s, 0);
        return move(perms);
    }
};