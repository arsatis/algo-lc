class Solution {
public:
    bool backspaceCompare(string s, string t) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        stack<char> st1, st2;
        
        for (char c : s) {
            if (c != '#') st1.push(c);
            else if (!st1.empty()) st1.pop();
        }
        for (char c : t) {
            if (c != '#') st2.push(c);
            else if (!st2.empty()) st2.pop();
        }
        
        if (st1.size() != st2.size()) return false;
        while (!st1.empty()) {
            char c1 = st1.top(), c2 = st2.top();
            if (c1 != c2) return false;
            st1.pop(); st2.pop();
        }
        return true;
    }
};