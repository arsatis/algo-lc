class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    bool isPrefixString(string s, vector<string>& words) {
        string comp =  "";
        for (string& word : words){
            comp += word;
            if(s == comp) return true;
            if(word.length() > s.length()) return false;
        }
        return false;
    }
};