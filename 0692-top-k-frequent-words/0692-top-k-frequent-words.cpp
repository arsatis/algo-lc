class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> um;
        for(const auto& w:words)
            ++um[w];

        int n = words.size();
        vector<set<string>> vecWords(n+1);
        for(const auto& [word, cnt]:um)
            vecWords[cnt].insert(word);

        vector<string> res;
        for(int i=n; i>=1; --i){
            for(const auto& w:vecWords[i]){
                res.push_back(w);
                if(res.size()==k)
                    return res;
            }
        }

        return res;
    }
};