class Solution {
    public int maxProduct(String[] words) {
        int max = (1 << 26) - 1;
        int mask[] = new int[words.length];
        for (int i = 0; i < words.length; ++i)
            for (int j = 0; j < words[i].length(); ++j) {
                mask[i] |= 1 << (words[i].charAt(j) - 'a');
                if (mask[i] == max)
                    break;
            }
        int output = 0;
        for (int i = 0; i < words.length - 1; ++i) {
            if (mask[i] == max) continue;
            for (int j = i + 1; j < words.length; ++j)
                if ((mask[i] & mask[j]) == 0)
                    output = Math.max(output, words[i].length() * words[j].length());
        }
        return output;
    }
}