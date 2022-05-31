class Solution {
    public boolean hasAllCodes(String s, int k) {
        int size = 1 << k;
        boolean[] found = new boolean[size];
        int num = 0, mask = size - 1, cnt = 0;
        char[] ca = s.toCharArray();
        for (int i = 0; i < ca.length; ++i) {
            num = mask & ((num << 1) + ca[i] - '0');
            if (i >= k - 1) {
                if (found[num] == false)
                    ++cnt;
                found[num] = true;
            }
        }
        return cnt == size;
    }
}