class Solution {
public:
    int calculate(string& s) {
        stack<int> st;
        int currN = 0;
        char operation = '+';
        for (int i = 0; i < s.size(); i++) {
            char currC = s[i];
            if (isdigit(currC)) currN = (currN * 10) + (currC - '0');
            if (!isdigit(currC) && !iswspace(currC) || i == s.size() - 1) {
                if (operation == '-') {
                    st.push(-currN);
                } else if (operation == '+') {
                    st.push(currN);
                } else if (operation == '*') {
                    int stackTop = st.top();
                    st.pop();
                    st.push(stackTop * currN);
                } else if (operation == '/') {
                    int stackTop = st.top();
                    st.pop();
                    st.push(stackTop / currN);
                }
                operation = currC;
                currN = 0;
            }
        }
        int result = 0;
        while (!st.empty()) result += st.top(), st.pop();
        return result;
    }
};