class Solution {
    struct wordComp{
        bool operator()(pair<string, int>& a, pair<string, int>& b) {
            return a.second != b.second ? a.second < b.second : a.first > b.first;
        }
    };
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordCounts;
        for (string& word : words) ++wordCounts[word];
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, wordComp> pq;
        for (auto& p : wordCounts) pq.push(p);
        
        vector<string> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return move(result);
    }
};