class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.size()+ 1, vector<int>(p.size() + 1));
        return dp(s, p, 0, 0, memo);
    }
    
    bool dp(const string& s, const string& p, int i, int j, vector<vector<int>>& memo) {
        if (j >= p.size()) return i == s.size();
        bool is_match = i < s.size() && (s[i] == p[j] || p[j] == '.');
        bool res;
        
        if (memo[i][j] != 0) return memo[i][j] == 1 ? true : false;
        
        if (j + 1 < p.size() && p[j + 1] == '*') res = dp(s, p, i, j + 2, memo) || (is_match && dp(s, p, i + 1, j, memo));
        else res = is_match && dp(s, p, i + 1, j + 1, memo);
        
        if (res) memo[i][j] = 1;
        else memo[i][j] = 2;
        
        return res;
    }
};