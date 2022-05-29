import java.util.HashMap;

class Solution {
    public int maxProduct(String[] words) {
        HashMap<Integer, Integer> hm =  new HashMap<>();
        for (String word : words) {
            int mask = 0;
            for (int i = 0; i < word.length(); ++i)
                mask |= 1 << (word.charAt(i) - 'a');
            hm.put(mask, Math.max(hm.getOrDefault(mask, 0), word.length()));
        }
        int output = 0;
        for (Integer i : hm.keySet()) {
            for (Integer j : hm.keySet()) {
                if ((i & j) == 0) {
                    output = Math.max(output, hm.get(i) * hm.get(j));
                }
            }
        }
        return output;
    }
}