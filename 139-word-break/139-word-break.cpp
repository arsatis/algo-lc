class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        ios_base::sync_with_stdio(0);
        vector<bool> reached(s.length(), false);
        queue<int> posns;
        
        posns.push(0);
        
        for (int start; !posns.empty(); posns.pop()) {
            start = posns.front();
            
            for (const auto& w : wordDict) {
                if (start + w.length() <= s.length() && 
                    !reached[start + w.length() - 1] &&
                    s.compare(start, w.length(), w) == 0) 
                {
                    posns.push(start + w.length());
                    reached[start + w.length() - 1] = true;
                    
                    if (reached.back()) return true;
                }
            }
        }
        
        return false;
    }
};