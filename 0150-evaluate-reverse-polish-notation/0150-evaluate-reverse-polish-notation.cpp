class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int64_t> stk;
        
        for (auto token : tokens) {
            if (token == "+") {
                auto b = stk.top(); stk.pop();
                auto a = stk.top(); stk.pop();
                stk.push(a + b);
            } else if (token == "-") {
                auto b = stk.top(); stk.pop();
                auto a = stk.top(); stk.pop();
                stk.push(a - b);
            } else if (token == "*") {
                auto b = stk.top(); stk.pop();
                auto a = stk.top(); stk.pop();
                stk.push(a * b);
            } else if (token == "/") {
                auto b = stk.top(); stk.pop();
                auto a = stk.top(); stk.pop();
                stk.push(a / b);
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};