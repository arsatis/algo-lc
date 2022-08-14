class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (string &s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            groups[temp].push_back(s);
        }
        
        vector<vector<string>> output;
        for (auto it = groups.begin(); it != groups.end(); ++it) {
            output.push_back(it->second);
        }
        return output;
    }
};