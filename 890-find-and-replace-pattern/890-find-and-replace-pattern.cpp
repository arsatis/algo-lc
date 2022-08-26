class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<string> ans;
        
        for (string& i : words) {
            map<char, int> mp1, mp2;
            int cn = 0;
            bool temp = true;
            for (char& j : i) {
                if (mp1.find(pattern[cn]) == mp1.end() && mp2.find(j) == mp2.end()) {
                    mp1[pattern[cn]] = j;
                    mp2[j] = pattern[cn];
                } else if (mp1[pattern[cn]] != j) {
                    temp = false;
                    break;
                }
                ++cn;
            }
            if (temp) ans.push_back(i);
        }
        return ans;
    }
};