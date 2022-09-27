class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;
        for (int i = 0; i < arr.size(); ++i) {
            if (seen.find(2 * arr[i]) != seen.end() ||
                ((arr[i] & 1) == 0 && seen.find(arr[i] / 2) != seen.end())) return true;
            seen.insert(arr[i]);
        }
        return false;
    }
};