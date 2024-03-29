class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        unordered_map<int, int> counts;
        for (int& i : nums) ++counts[i];
        
        vector<int> buckets[nums.size() + 1];
        for (auto& pair : counts) buckets[pair.second].push_back(pair.first);
        
        vector<int> mostFreq(k);
        int outerIdx = nums.size(), innerIdx = 0;
        for (int i = 0; i < k; ++i) {
            while (buckets[outerIdx].size() == 0) --outerIdx;
            mostFreq[i] = buckets[outerIdx][innerIdx];
            if (buckets[outerIdx].size() <= ++innerIdx) {
                --outerIdx;
                innerIdx = 0;
            }
        }
        return mostFreq;
    }
};