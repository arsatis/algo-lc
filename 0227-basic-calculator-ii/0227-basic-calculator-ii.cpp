class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int calculate(string& s) {
        int len = s.length(), currentNumber = 0, lastNumber = 0, result = 0;
        char sign = '+';
        for (int i = 0; i < len; ++i) {
            char currentChar = s[i];
            if (isdigit(currentChar)) currentNumber = (currentNumber * 10) + (currentChar - '0');
            if (!isdigit(currentChar) && !isspace(currentChar) || i == len - 1) {
                if (sign == '*') lastNumber = lastNumber * currentNumber;
                else if (sign == '/') lastNumber = lastNumber / currentNumber;
                else {
                    result += lastNumber;
                    lastNumber = (sign == '+') ? currentNumber : -currentNumber;
                }
                sign = currentChar;
                currentNumber = 0;
            }
        }
        result += lastNumber;
        return result;
    }
};