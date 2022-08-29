class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        ios_base::sync_with_stdio(0);
        
        unordered_map<string, int> counts;
        for (string& word : words) ++counts[word];
        
        priority_queue<string, deque<string>, greater<string>> buckets[words.size() + 1];
        for (auto& pair : counts) buckets[pair.second].push(pair.first);
        
        vector<string> mostFreq(k);
        int idx = words.size();
        for (int i = 0; i < k; ++i) {
            while (buckets[idx].size() == 0) --idx;
            mostFreq[i] = buckets[idx].top();
            buckets[idx].pop();
            if (buckets[idx].size() == 0) --idx;
        }
        return mostFreq;
    }
};