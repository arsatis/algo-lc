class TimeMap {
    unordered_map<string, vector<pair<int, string>>> store;
public:
    TimeMap() {
        ios_base::sync_with_stdio(0);
    }
    
    void set(string key, string value, int timestamp) {
        store[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end() || store[key].front().first > timestamp) return "";
        auto& vec = store[key];
        int left = 0, right = vec.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (vec[mid].first == timestamp) return vec[mid].second;
            else if (vec[mid].first > timestamp) right = mid - 1;
            else left = mid;
        }
        return vec[left].first <= timestamp ? vec[left].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */