class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        bool seen[2001] = { false };
        for (int i : arr) {
            if ((i & 1) == 0 && seen[(i / 2) + 1000]) return true;
            if (abs(i * 2) <= 1000 && seen[(i * 2) + 1000]) return true;
            seen[i + 1000] = true;
        }
        return false;
    }
};