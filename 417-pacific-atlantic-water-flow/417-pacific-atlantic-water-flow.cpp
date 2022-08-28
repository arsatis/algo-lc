class Solution {
    void bfs(vector<vector<int>>& heights, vector<vector<int>>& matrix, int ocean, int i, int j) {
        if ((matrix[i][j] & ocean) == ocean) return;
        matrix[i][j] += ocean;
        
        // left
        if (i > 0 && (matrix[i - 1][j] & ocean) != ocean
                  && heights[i - 1][j] >= heights[i][j])
            bfs(heights, matrix, ocean, i - 1, j);
        // right
        if (i < matrix.size() - 1 && (matrix[i + 1][j] & ocean) != ocean
                                  && heights[i + 1][j] >= heights[i][j])
            bfs(heights, matrix, ocean, i + 1, j);
        // up
        if (j > 0 && (matrix[i][j - 1] & ocean) != ocean
                  && heights[i][j - 1] >= heights[i][j])
            bfs(heights, matrix, ocean, i, j - 1);
        // down
        if (j < matrix[0].size() - 1 && (matrix[i][j + 1] & ocean) != ocean
                                     && heights[i][j + 1] >= heights[i][j])
            bfs(heights, matrix, ocean, i, j + 1);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ios_base::sync_with_stdio(0);
        
        vector<vector<int>> matrix(heights.size(), vector<int>(heights[0].size()));
        for (int i = 0; i < matrix.size(); ++i) {
            bfs(heights, matrix, 1, i, 0);
            bfs(heights, matrix, 2, i, matrix[0].size() - 1);
        }
        for (int i = 0; i < matrix[0].size(); ++i) {
            bfs(heights, matrix, 1, 0, i);
            bfs(heights, matrix, 2, matrix.size() - 1, i);
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[0].size(); ++j)
                if (matrix[i][j] == 3) result.push_back({ i, j });
        
        return result;
    }
};