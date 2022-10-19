class Solution {
    struct wordComp{
        bool operator()(pair<string, int> & a, pair<string, int> & b){
            // return a < b
            if(a.second < b.second){
                return true;
            }
            else if(a.second > b.second){
                return false;
            }
            else{
                // equal, higher priority goes to lower lexicographic string
                return b.first < a.first;
            }
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
        for(string & word : words){
            wordCounts[word]++;
        }
        
        // put everything into a pq using wordComp
        priority_queue<pair<string, int>, vector<pair<string, int>>, wordComp> pq;
        for(auto p : wordCounts){
            pq.push(p);
        }
        
        vector<string> result;
        // loop k times, grab the top k 
        for(int i = 0; i < k; i++){
            result.push_back(pq.top().first);
            pq.pop();
        }
        
        return result;
    }
};