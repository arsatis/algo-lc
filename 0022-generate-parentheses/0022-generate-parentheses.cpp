class Solution {
    vector<string> output;
    void f(string s, int left, int right) {
        if (left == 0) {
            for (int i = 0; i < right; ++i) s += ')';
            output.emplace_back(s);
        } else {
            if (left < right) f(s + ')', left, right - 1);
            f(s + '(', left - 1, right);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        f("", n, n);
        return move(output);
    }
};
