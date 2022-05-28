import java.util.Arrays;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] curr = new int[256];
        Arrays.fill(curr, -1);
        int maxLen = 0;
        int start = -1;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (curr[c] > start)
                start = curr[c];
            curr[c] = i;
            maxLen = Math.max(maxLen, i - start);
        }
        return maxLen;
    }
}