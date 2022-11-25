class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> reached(s.size());
        queue<int> posns;
        posns.push(0);
        
        for (int start; !posns.empty(); posns.pop()) {
            start = posns.front();
            for (auto& w : wordDict) {
                if (start + w.length() <= s.length() &&
                    !reached[start + w.length() - 1] &&
                    s.compare(start, w.length(), w) == 0) {
                    posns.push(start + w.length());
                    reached[start + w.length() - 1] = true;
                    if (reached.back()) return true;
                }
            }
        }
        return false;
    }
};
