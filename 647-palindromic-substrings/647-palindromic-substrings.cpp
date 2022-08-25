class Solution {
public:
    int countSubstrings(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int num = 0;
        for (int i = 0; i < (s.size() << 1); ++i) {
            int left = i >> 1, right = (i + 1) >> 1, size = 0;
            while (left - size >= 0 && right + size < s.size()) {
                if (s[left - size] != s[right + size]) break;
                ++num;
                ++size;
            }
        }
        return num;
    }
};