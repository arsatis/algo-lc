class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;        
        long copy = 0;
        long temp = x;
        while (temp != 0) {
            int l = temp % 10;
            copy = copy * 10 + l;
            temp = temp / 10;
        }
        
        return copy == x;
    }
};