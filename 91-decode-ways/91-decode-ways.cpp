class Solution {
public:
    int numDecodings(string s) {
        int prev = 1, prev2, n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            // is the single digit s[i] valid?
            int curr = s[i] == '0' ? 0 : prev;
            
            // are the two digits s[i:i+1] valid?
            if (i < n - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7'))
                curr += prev2;
            
            // update curr states
            prev2 = prev;
            prev = curr;
        }
        return s.empty() ? 0 : prev;  
    }
};