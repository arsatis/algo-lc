class Solution {
public:
    string reverseWords(string s) {
        ios_base::sync_with_stdio(0);

        auto prev = s.begin(), curr = s.begin();
        while ((curr = find(curr, s.end(), ' ')) != s.end()) {
            reverse(prev, curr);
            prev = ++curr;
        }
        reverse(prev, curr);
        return s;
    }
};