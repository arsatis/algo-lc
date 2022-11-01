class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int arr[10001] = {};
        for (int i = 0; i < mat.size(); ++i)
            for (int j = 0; j < mat[0].size(); ++j)
                ++arr[mat[i][j]];
        for (int i = 0; i < 10001; ++i) if (arr[i] == mat.size()) return i;
        return -1;
    }
};