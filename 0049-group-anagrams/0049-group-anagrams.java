class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, ArrayList<String>> anagrams = new HashMap<>();
        for (String s : strs) {
            char[] c = s.toCharArray();
            Arrays.sort(c);
            String sNew = new String(c);
            if (anagrams.containsKey(sNew)) anagrams.get(sNew).add(s);
            else anagrams.put(sNew, new ArrayList<>(Arrays.asList(s)));
        }
        
        List<List<String>> list = new ArrayList<>();
        for (List<String> a : anagrams.values()) list.add(a);
        return list;
    }
}