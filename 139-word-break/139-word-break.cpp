class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
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