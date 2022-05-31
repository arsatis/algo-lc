class Solution {
    public boolean hasAllCodes(String s, int k) {
        boolean[] found = new boolean[1 << k];
        int num = 0, mask = (1 << k) - 1, cnt = 0;
        char[] ca = s.toCharArray();
        for (int i = 0; i < ca.length; ++i) {
            num = mask & ((num << 1) + ca[i] - '0');
            if (i >= k - 1) {
                if (found[num] == false)
                    ++cnt;
                found[num] = true;
            }
        }
        return cnt == found.length;
    }
}