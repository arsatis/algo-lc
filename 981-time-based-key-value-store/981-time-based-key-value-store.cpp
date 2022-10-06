class TimeMap {
    unordered_map<string, vector<pair<int, string>>> store;
public:
    TimeMap() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    void set(string key, string value, int timestamp) {
        store[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end() || timestamp < store[key].front().first) return "";
        
        int left = 0, right = store[key].size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (store[key][mid].first <= timestamp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (right == 0) return "";
        return store[key][right - 1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */