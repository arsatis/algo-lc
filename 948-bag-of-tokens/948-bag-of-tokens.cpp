class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        ios_base::sync_with_stdio(0);
        
        if (tokens.size() < 1) return 0;
        
        int score = 0, maxScore = 0;
        sort(tokens.begin(), tokens.end());
        for (int l = 0, r = tokens.size() - 1; l <= r;) {
            if (power >= tokens[l]) ++score, power -= tokens[l++];
            else if (score > 0) --score, power += tokens[r--];
            else return maxScore;
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};