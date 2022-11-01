class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, ArrayList<String>> anagrams = new HashMap<>();
        for (String s : strs) {
            char[] c = s.toCharArray();
            Arrays.sort(c);
            String sNew = new String(c);
            if (!anagrams.containsKey(sNew)) anagrams.put(sNew, new ArrayList<>());
            anagrams.get(sNew).add(s);
        }
        return new ArrayList(anagrams.values());
    }
}