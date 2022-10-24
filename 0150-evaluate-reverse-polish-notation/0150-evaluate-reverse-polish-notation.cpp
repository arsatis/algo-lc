class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<long(long, long)>> op = {
            { "+" , [](long a, long b) { return a + b; } },
            { "-" , [](long a, long b) { return a - b; } },
            { "*" , [](long a, long b) { return a * b; } },
            { "/" , [](long a, long b) { return a / b; } }
        };
        stack<long> st;
        for (string& s : tokens) {
            if (op.find(s) == op.end()) st.push(stoi(s));
            else {
                long op1 = st.top(); st.pop();
                long op2 = st.top(); st.pop();
                st.push(op[s](op2, op1));
            }
        }
        return st.top();
    }
};