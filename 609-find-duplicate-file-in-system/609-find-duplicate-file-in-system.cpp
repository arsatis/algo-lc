class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> dict;
        
        for (const string& path : paths) {
            string pathStart;
            int i = 0;
            while (path[i] != ' ') pathStart.push_back(path[i++]);
            ++i;
            
            while (i < path.size()) {
                string fileName, fileData;
                while (path[i] != '(') fileName.push_back(path[i++]);
                ++i;
                
                while (path[i] != ')') fileData.push_back(path[i++]);
                i += 2;
                dict[fileData].push_back(pathStart + "/" + fileName);
            }     
        }
        
        vector<vector<string>> dups;
        for (auto& [key, value] : dict) if (value.size() > 1) dups.emplace_back(move(value));
        return move(dups);
    }
};