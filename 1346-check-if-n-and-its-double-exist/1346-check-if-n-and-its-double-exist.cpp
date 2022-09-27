class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> set;
        for (int i = 0; i < arr.size(); ++i){
            if (set.count(2 * arr[i]) > 0 || ((arr[i] & 1) == 0 && set.count(arr[i] / 2) > 0)) return true;
            set.insert(arr[i]);
        }
        return false;
    }
};