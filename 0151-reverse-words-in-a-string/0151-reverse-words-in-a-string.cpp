class Solution {
public:
    string reverseWords(string& s) {
        stack<string> st;
        string curr = "";
        for (char c : s) {
            if (c != ' ') curr += c;
            else if (!curr.empty()) st.emplace(curr), curr = "";
        }
        if (!curr.empty()) st.emplace(curr);

        string output = "";
        while (!st.empty()) {
            output += st.top();
            st.pop();
            if (!st.empty()) output += ' ';
        }
        return move(output);
    }
};
