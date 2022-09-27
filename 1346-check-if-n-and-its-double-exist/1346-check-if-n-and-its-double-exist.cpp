class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> seen;
        for (int i : arr) {
            if (seen.find(i * 2) != seen.end() || (i & 1) == 0 && seen.find(i * 0.5) != seen.end()) return true;
            seen.insert(i);
        }
        return false;
    }
};