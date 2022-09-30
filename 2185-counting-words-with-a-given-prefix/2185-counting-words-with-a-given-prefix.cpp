class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    int prefixCount(vector<string>& words, string& pref) {
        int num = 0;
        for (string& w : words) if (w.find(pref) == 0) ++num;
        return num;
    }
};