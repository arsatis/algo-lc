class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int out1 = 0, in1 = 0, out2 = 0, in2 = 0;
        while (out1 < word1.size() || out2 < word2.size()) {
            if (out1 == word1.size() || out2 == word2.size() || word1[out1][in1] != word2[out2][in2]) return false;
            ++in1, ++in2;
            if (in1 == word1[out1].size()) ++out1, in1 = 0;
            if (in2 == word2[out2].size()) ++out2, in2 = 0;
        }
        return true;
    }
};