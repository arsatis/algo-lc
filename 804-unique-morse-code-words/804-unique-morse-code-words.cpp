class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        ios_base::sync_with_stdio(0);
        
        string mappings[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> unique;
        for (string& w : words) {
            string s = "";
            for (char& c : w) s += mappings[c - 'a'];
            unique.insert(s);
        }
        return unique.size();
    }
};