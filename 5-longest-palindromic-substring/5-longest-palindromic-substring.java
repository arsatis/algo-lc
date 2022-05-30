class Solution {
    public String longestPalindrome(String s) {
        int start = 0, end = 0;
        char[] ca = s.toCharArray(); // apparently array access >> string random access
        for (int i = 0; i < ca.length; ++i) {
            char c = ca[i];
            int left = i;
            int right = i;
            while (left >= 0 && ca[left] == c) --left;
            while (right < ca.length && ca[right] == c) ++right;
            while (left >= 0 && right < ca.length) {
                if (ca[left] != ca[right]) break;
                --left;
                ++right;
            }
            ++left;
            if (end - start < right - left) {
                start = left;
                end = right;
            }
        }
        return s.substring(start, end);
    }
}