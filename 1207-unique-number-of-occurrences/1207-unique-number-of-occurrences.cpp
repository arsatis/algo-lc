class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int counter[2001] = {};
        for (int x : arr) ++counter[x + 1000];

        bool unique[1001] = {};
        for (int x : counter) if (x != 0) {
            if (!unique[x]) unique[x] = true;
            else return false;
        }
        return true;
    }
};
