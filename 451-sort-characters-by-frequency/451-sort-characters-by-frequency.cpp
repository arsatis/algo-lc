class Solution {
public:
    string frequencySort(string s) {
        ios_base::sync_with_stdio(0);
        
        vector<int> freq(128, 0);
        for (char c : s) ++freq[c];
        
        string res;
        int sz = 0;
        while (sz < s.size()) {
            auto it = max_element(freq.begin(), freq.end());
            sz += *it;
            int ch = it - freq.begin();
            while (freq[ch]-- > 0) res.push_back(ch);
        }
        return res;
    }
};