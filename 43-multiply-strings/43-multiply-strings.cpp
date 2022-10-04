class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int n = num1.size() + num2.size();
        string answer(n, '0');
        
        for (int place2 = 0; place2 < num2.size(); ++place2) {
            int digit2 = num2[place2] - '0';
            for (int place1 = 0; place1 < num1.size(); ++place1) {
                int digit1 = num1[place1] - '0';
                
                int numZeros = place1 + place2;
                int carry = answer[numZeros] - '0';
                int prod = digit1 * digit2 + carry;
                
                answer[numZeros] = (prod % 10) + '0';
                answer[numZeros + 1] += (prod / 10);
            }
        }
        
        if (answer.back() == '0') answer.pop_back();
        reverse(answer.begin(), answer.end());
        return answer;
    }
};