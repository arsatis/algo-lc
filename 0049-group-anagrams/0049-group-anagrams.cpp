class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (string& s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            groups[temp].emplace_back(s);
        }
        
        vector<vector<string>> output;
        output.reserve(groups.size());
        for (auto& item : groups) output.emplace_back(item.second);
        return output;
    }
};
