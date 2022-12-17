class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<long(long, long)>> op = {
            { "+" , [](long a, long b) { return a + b; } },
            { "-" , [](long a, long b) { return a - b; } },
            { "*" , [](long a, long b) { return a * b; } },
            { "/" , [](long a, long b) { return a / b; } }
        };
        stack<long> nums;
        for (string& token : tokens) {
            if (!op.count(token)) nums.emplace(stoi(token));
            else {
                long x = nums.top(); nums.pop();
                long y = nums.top(); nums.pop();
                nums.emplace(op[token](y, x));
            }
        }
        return nums.top();
    }
};
