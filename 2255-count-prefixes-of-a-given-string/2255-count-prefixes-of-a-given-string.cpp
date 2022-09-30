class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int countPrefixes(vector<string>& words, string s) {
        int num = 0;
        for (string& w : words) if (s.find(w) == 0) ++num;
        return num;
    }
};