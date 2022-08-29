class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counts;
        for (string& word : words) ++counts[word];
        
        vector<string> buckets[words.size() + 1];
        for (auto& pair : counts) buckets[pair.second].push_back(pair.first);
        
        vector<string> mostFreq(k);
        int outerIdx = words.size(), innerIdx = 0;
        for (int i = 0; i < k; ++i) {
            while (buckets[outerIdx].size() == 0) --outerIdx;
            sort(buckets[outerIdx].begin(), buckets[outerIdx].end());
            mostFreq[i] = buckets[outerIdx][innerIdx];
            if (buckets[outerIdx].size() <= ++innerIdx) {
                --outerIdx;
                innerIdx = 0;
            }
        }
        return mostFreq;
    }
};