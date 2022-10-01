class Solution {
public:
    int numDecodings(string s) {
        int prev1 = 1, prev2, n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            // is the single digit s[i] valid?
            int curr = s[i] == '0' ? 0 : prev1;
            
            // are the two digits s[i:i+1] valid?
            int twoDigit = stoi(s.substr(i, 2));
            if (twoDigit >= 10 && twoDigit <= 26) curr += prev2;
            
            // update curr states
            prev2 = prev1;
            prev1 = curr;
        }
        return s.empty() ? 0 : prev1;  
    }
};