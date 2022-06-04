class Solution {
public:
    bool isPalindrome(int x) {
        string m = to_string(x);
        int n = m.size();
        int i = 0, j = n - 1;
        while (i <= j) {
            if (m[i] != m[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
};