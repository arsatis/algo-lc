class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char& c : s) {
            if (c == '{') st.push('}');
            else if (c == '[') st.push(']');
            else if (c == '(') st.push(')');
            else if (c == ')' || c == '}' || c == ']') {
                if (st.size() == 0) return false;
                char d = st.top(); st.pop();
                if (d != c) return false;
            }
        }
        return st.size() == 0;
    }
};