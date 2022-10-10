class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    string breakPalindrome(string& palindrome) {
        if (palindrome.size() == 1) return "";
        bool isOdd = palindrome.size() & 1;
        int i = 0, mid = palindrome.size() >> 1;
        for (; i < palindrome.size(); ++i)
            if (palindrome[i] != 'a' && (!isOdd || i != mid)) {
                palindrome[i] = 'a';
                break;
            }
        if (i == palindrome.size()) palindrome.back() = 'b';
        return palindrome;
    }
};