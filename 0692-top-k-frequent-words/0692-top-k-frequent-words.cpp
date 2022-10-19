class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::unordered_map<std::string, int> wordFreqHash;
        for (int i = 0; i < words.size(); ++i)
        {
            ++wordFreqHash[words[i]];
        }
        
        auto comp = [] (auto left, auto right)
        {
            return (  left.first > right.first
                   || (  left.first == right.first
                      && left.second < right.second));
        };
        std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, decltype(comp)> pq(comp);
        for (auto &[word, freq] : wordFreqHash)
        {
            pq.push(std::make_pair(freq, word));
            if (pq.size() > k)
                pq.pop();
        }

        std::vector<std::string> result(pq.size());
        auto it = result.rbegin();
        while (!pq.empty())
        {
            *it++ = pq.top().second;
            pq.pop();
        }
        
        return result;
    }
};