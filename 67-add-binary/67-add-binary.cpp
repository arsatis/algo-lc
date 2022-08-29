class Solution {
public:
    string addBinary(string a, string b) {
        ios_base::sync_with_stdio(0);
        
        string res;
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum > 1 ? 1 : 0;
            res += to_string(sum % 2);
        }
        if (carry) res += to_string(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};