class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> dict;
        
        for (string& s : paths) {
            auto it = find(s.begin(), s.end(), ' ');
            string path_to_file(s.begin(), it);
            
            while (it != s.end()) {
                auto content_start = find(++it, s.end(), '('),
                     content_end = find(content_start, s.end(), ')');
                string file_name(it, content_start++), key(content_start, content_end);
                
                dict[key].emplace_back(path_to_file + '/' + file_name);
                it = find(content_end, s.end(), ' ');
            }
        }
        
        vector<vector<string>> dups;
        for (auto& p : dict) if (p.second.size() > 1) dups.emplace_back(move(p.second));
        return move(dups);
    }
};