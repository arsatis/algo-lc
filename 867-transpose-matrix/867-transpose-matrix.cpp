#include <vector>

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> vvi;
        for (int i = 0; i < matrix[0].size(); ++i) {
            vector<int> vi;
            for (int j = 0; j < matrix.size(); ++j)
                vi.push_back(matrix[j][i]);
            vvi.push_back(vi);
        }
        return vvi;
    }
};