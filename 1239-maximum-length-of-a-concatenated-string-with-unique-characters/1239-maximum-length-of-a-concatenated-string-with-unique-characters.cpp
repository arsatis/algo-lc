class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int maxLength(vector<string>& arr) {
        size_t maxLen = 0;
        vector<bitset<26>> unique;
        unique.reserve(arr.size());
        
        // throw away strings with dup characters
        for (string& s : arr) {
            bitset<26> tmp;
            for (char c : s) tmp |= (1 << c - 'a');
            if (tmp.count() == s.size()) unique.emplace_back(tmp);
        }
        
        // starting with empty concatenation, iteratively increase
        // its length by trying to add more strings
        vector<bitset<26>> concat(1);
        for (auto& bs : unique) {
            for (int i = concat.size() - 1; i >= 0; --i) {
                if ((concat[i] & bs).none()) {
                    concat.emplace_back(concat[i] | bs);
                    maxLen = max(maxLen, concat[i].count() + bs.count());
                }
            }
        }
        return maxLen;
    }
};