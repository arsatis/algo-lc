class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string output;
        int n = max(num1.size(), num2.size()), carry = 0;
        for (int i = 0; i < n; ++i) {
            int val1 = i < num1.size() ? num1[i] - '0' : 0,
                val2 = i < num2.size() ? num2[i] - '0' : 0,
                sum = val1 + val2 + carry;
            output += sum % 10 + '0';
            carry = sum / 10;
        }
        if (carry > 0) output += carry + '0';
        reverse(output.begin(), output.end());
        return output;
    }
};