class Solution {
public:
    string convertToTitle(int n) {
        ios_base::sync_with_stdio(0);
        
        string ans;
        while (n > 0) {
            --n;
            int curr = n % 26;
            n /= 26;
            ans.push_back(curr + 'A');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};