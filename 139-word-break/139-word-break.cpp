class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.empty()) return false;
        
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j]) {
                    if (find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                        dp[i] = true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};