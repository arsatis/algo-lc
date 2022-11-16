class Solution {
public:
    int shortestWay(string& source, string& target) {
        int m = source.size(), n = target.size();
        
        // Build inverted index for source
        int dict[m][26];
        memset(dict, -1, sizeof(dict));
        dict[m - 1][source[m - 1] - 'a'] = m - 1;
        for (int x = m - 2; x >= 0; --x) {
            for (int i = 0; i < 26; ++i) dict[x][i] = dict[x + 1][i];
            dict[x][source[x] - 'a'] = x;
        }
        
        int ans = 0, idx = 0;
        for (char c : target) {
            // If there are no occurrences of c with index greater than 0
            // then it doesn't occur at all. Hence, we cannot get that letter from
            // a subsequence of source.
            if (dict[0][c - 'a'] == -1) return -1;
            
            // If there are no c's left in source that occur >= idx
            // but there are c's from earlier in the subsequence
            // add 1 to subsequence count and reset idx of source to 0.
            if (dict[idx][c - 'a'] == -1) ++ans, idx = 0;
            
            // Then continue taking letters from the subsequence
            idx = dict[idx][c - 'a'] + 1;
            
            if (idx == m) ++ans, idx = 0;
        }
        return ans + (idx == 0 ? 0 : 1);
    }
};
