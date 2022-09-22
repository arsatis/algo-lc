class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    string reverseWords(string s) {
        auto prev = s.begin(), curr = s.begin();
        while ((curr = find(curr, s.end(), ' ')) != s.end()) {
            reverse(prev, curr);
            prev = ++curr;
        }
        reverse(prev, curr);
        return s;
    }
};