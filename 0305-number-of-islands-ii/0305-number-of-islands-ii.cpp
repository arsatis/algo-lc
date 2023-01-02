class Solution {
    pair<int, int> find(vector<vector<pair<int, int>>>& mat, int x, int y) {
        if (mat[x][y] == make_pair(x, y)) return mat[x][y];
        return mat[x][y] = find(mat, mat[x][y].first, mat[x][y].second);
    }
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int disjoint = 0;
        const pair<int, int> invalid_pair = {-1, -1};
        vector<vector<pair<int, int>>> mat(m, vector<pair<int, int>>(n, invalid_pair));
        vector<int> output;
        output.reserve(positions.size());

        for (auto& v : positions) {
            if (mat[v[0]][v[1]] == invalid_pair) {
                mat[v[0]][v[1]] = {v[0], v[1]}, ++disjoint;
                if (v[0] > 0 && mat[v[0] - 1][v[1]] != invalid_pair) {
                    auto [x, y] = find(mat, v[0] - 1, v[1]);
                    mat[x][y] = {v[0], v[1]}, --disjoint;
                }
                if (v[1] > 0 && mat[v[0]][v[1] - 1] != invalid_pair) {
                    auto [x, y] = find(mat, v[0], v[1] - 1);
                    if (v[0] != x || v[1] != y) mat[x][y] = {v[0], v[1]}, --disjoint;
                }
                if (v[0] < m - 1 && mat[v[0] + 1][v[1]] != invalid_pair) {
                    auto [x, y] = find(mat, v[0] + 1, v[1]);
                    if (v[0] != x || v[1] != y) mat[x][y] = {v[0], v[1]}, --disjoint;
                }
                if (v[1] < n - 1 && mat[v[0]][v[1] + 1] != invalid_pair) {
                    auto [x, y] = find(mat, v[0], v[1] + 1);
                    if (v[0] != x || v[1] != y) mat[x][y] = {v[0], v[1]}, --disjoint;
                }
            }
            output.emplace_back(disjoint);
        }
        return move(output);
    }
};
