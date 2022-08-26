class Solution {
public:
    bool check(int i, int j, const string &text, const string &pattern, vector<vector<int>> &lookupTable){
        if (i >= text.size() && j >= pattern.size()) return true;
        if (i >= text.size()) {
            if (pattern[j] == '*') return check(i, j + 1, text, pattern, lookupTable);
            else if (j + 1 < pattern.size() && pattern[j + 1] == '*') return check(i, j + 2, text, pattern, lookupTable);
            else return false;
        }
        if (j >= pattern.size()) return false;
        if (lookupTable[i][j] != -1) return lookupTable[i][j] == 1 ? true : false;
        
        bool match = false;
        if (j + 1 < pattern.size() && pattern[j + 1]=='*') {
            if (text[i] == pattern[j] || pattern[j] == '.') {
                match |= check(i + 1, j + 2, text, pattern, lookupTable);
                match |= check(i + 1, j, text, pattern, lookupTable);
            }
            match |= check(i, j + 2, text, pattern, lookupTable);
        } else if (pattern[j] == '.' || text[i] == pattern[j]) {
            match |= check(i + 1, j + 1, text, pattern, lookupTable);
        } else {
            lookupTable[i][j] = match ? 1 : 0; 
            return lookupTable[i][j] == 1 ? true: false;
        }
        
        lookupTable[i][j] = match ? 1 : 0; 
        return lookupTable[i][j] == 1 ? true : false;
    }
    
    bool isMatch(string &s, string &p) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<vector<int>> lookupTable(s.size(), vector<int>(p.size(), -1));
        return check(0, 0, s, p, lookupTable);   
    }
};