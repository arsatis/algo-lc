class Solution {
    void f(vector<string>& perms, string& s, int begin) {
        if (begin >= s.size()) {
            perms.push_back(s);
            return;
        }
        while (begin < s.size()) {
            if (isalpha(s[begin])) break;
            ++begin;
        }
        f(perms, s, begin + 1);
        if (isalpha(s[begin])) {
            if (islower(s[begin])) s[begin] -= 32;
            else s[begin] += 32;
            f(perms, s, begin + 1);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<string> perms;
        f(perms, s, 0);
        return move(perms);
    }
};