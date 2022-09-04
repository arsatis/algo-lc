class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        ios_base::sync_with_stdio(0);
        
        int diff = 0;
        char diffChar[2];
        
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (diff > 1) return false;
                else if (diff == 1) {
                    if (diffChar[0] != s2[i] || diffChar[1] != s1[i])
                        return false;
                } else {
                    diffChar[0] = s1[i];
                    diffChar[1] = s2[i];
                }
                ++diff;
            }
        }
        return !diff || diff == 2;
    }
};